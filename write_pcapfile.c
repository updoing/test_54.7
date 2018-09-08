
unsigned int pcap_count = 0;

int write_data2file(unsigned char* ptr, size_t nmemb, FILE * stream)
{
	int64_t curWritten = 0;
	int64_t byteWritten = 0;
	int64_t total = nmemb;

	while ( byteWritten<total){
		curWritten = fwrite (ptr + byteWritten, 1, total-byteWritten, stream);
		if ( curWritten <= 0 ){
			break;
		}
		byteWritten+=curWritten;
	}
	if ( byteWritten!=total ){
	}
	fflush ( stream );
	return 0;
}

int write_skb2pcapfile(struct vs_skb *skb)
{

	if (!skb) {
		return 0;
	}
	
	vs_skb_reset_network_header(skb);
	vs_skb_push(skb, (skb->data - skb->mac.raw));
	
	char ipaddr[16] = {0};
	struct in_addr saddr;
	
	snprintf(ipaddr, 16, "192.168.54.24");
	inet_pton(AF_INET, ipaddr, (void*)&saddr);
	if (skb->nh.iph->saddr != saddr.s_addr)
		return 0;
	
	if (pcap_count >= 10) {
		return 0;
	}
#define FILEPATHMAXLEN 256
	char m_sFileName[FILEPATHMAXLEN + 1];
	memset(m_sFileName, 0, FILEPATHMAXLEN + 1);

	time_t timeInSecs = time(0);
	struct tm ctime;
	localtime_r(&timeInSecs, &ctime );
	snprintf(m_sFileName, 256, "%04d%02d%02d%02d%02d%02d_%d.cap",
			ctime.tm_year + 1900,ctime.tm_mon + 1, ctime.tm_mday,
			ctime.tm_hour, ctime.tm_min, ctime.tm_sec, pcap_count);

	char swapName[FILEPATHMAXLEN + 1];
	memset (swapName, 0 , FILEPATHMAXLEN + 1 );
	snprintf (swapName, FILEPATHMAXLEN, "%s/%s", "venus_dt", m_sFileName );

	FILE*	m_pWritePacketFile;
	m_pWritePacketFile = fopen(swapName, "wb");

	struct pcap_file_header {
		int32_t magic;
		u_short version_major;
		u_short version_minor;
		int32_t thiszone; /* gmt to local correction */
		u_int32_t  sigfigs; /* accuracy of timestamps */
		u_int32_t snaplen;	/* max length saved portion of each pkt */
		u_int32_t linktype; /* data link type (LINKTYPE_*) */
	};


	struct pcap_file_header hdr;
	hdr.magic = 0xA1B2C3D4;
	hdr.version_major = 2;
	hdr.version_minor = 4;

	hdr.thiszone = 0;
	hdr.sigfigs = 0;
	hdr.snaplen = 65535;
	hdr.linktype = 1;

	if (fwrite((char *)&hdr, sizeof(hdr), 1, m_pWritePacketFile) != 1) {
	}

	struct pcap_timeval {
	    int32_t tv_sec;		/* seconds */
	    int32_t tv_usec;		/* microseconds */
	};
	struct pcap_pkthdr {
		struct pcap_timeval ts;	/* time stamp */
		u_int32_t caplen; /* length of portion present */
		u_int32_t len;	/* length this packet (off wire) */
	};
	struct timeval tv;
	gettimeofday(&tv,NULL);
	struct pcap_pkthdr sf_hdr;
	sf_hdr.ts.tv_sec  = tv.tv_sec;
	sf_hdr.ts.tv_usec = tv.tv_usec;
	sf_hdr.caplen     = skb->len;
	sf_hdr.len        = skb->len;

	write_data2file((unsigned char *)&sf_hdr, sizeof(sf_hdr), m_pWritePacketFile);
	write_data2file(skb->data, skb->len, m_pWritePacketFile);
	vs_skb_pull(skb, (skb->nh.raw - skb->data));

	fclose(m_pWritePacketFile);	

	pcap_count++;

	return 0;
}

