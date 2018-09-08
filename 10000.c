#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

int main()
{
int sock;
sock=socket(AF_INET,SOCK_STREAM,0);
if(sock<0){
	printf("socket() fail!\n");
	return -1;
}

struct sockaddr_in server_conf;
memset((void *)&server_conf, 0, sizeof(server_conf));
server_conf.sin_family = AF_INET;
	server_conf.sin_port = htons(10000);
	//server_conf.sin_addr.s_addr = htonl(INADDR_ANY);
	if(inet_pton(AF_INET,"0.0.0.0", &server_conf.sin_addr) <= 0){
		printf("valid ip address\n");
		return 1;
	}

if(connect(sock, (struct sockaddr *)(&server_conf), sizeof(&server_conf)) < 0){
	printf("connect tcp:socket Connect TCP socket, %s", strerror(errno));
	close(sock);
	return -1;
	
}
char buf[100];
strcpy(buf,"zzb test  10000 port\n");
if(write(sock,buf,sizeof(buf))<0){
	printf("write  10000 port failed!\n");
	close(sock);
	return -1;
}
else{
	printf("write 1000 port success!\n");
}
char bufR[512];
if(read(sock,bufR,512)<0){
	printf("read 10000 port failed!\n");
	close(sock);
	return -1;
}
else{
	printf("read 10000 port success!\n");
}
close(sock);
printf("close(sock) has been done!\n");
return 0;
}

