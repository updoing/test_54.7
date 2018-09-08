#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct session {
	char name[102400];
	int sip;
	int dip;
	int sport;
	int dport;
};

int main (int argc, char *argv[])
{
	int j = 0;
	struct session *s = NULL;
begin:
	s = (struct session*)malloc(sizeof(struct session));

	if (!s) {
		printf("malloc is failed!\n");
		for (int i = 0; i < 16; i++) {
			sleep(1);
			s = (struct session*)malloc(sizeof(struct session));
			if (!s) {
				printf("malloc is again[%d] failed!\n", i);
			} else {
				printf("malloc is again[%d] ok!\n", i);
				free(s);
				s = NULL;
			}
		}
	} else {
		printf("malloc is ok![%d]\n", ++j);
		free(s);
		s = NULL;
		if (j < 64) {
			goto begin;
		}
	}

	return 0;
}
