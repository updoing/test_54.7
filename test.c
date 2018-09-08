#include <stdio.h>
//modify by issacli 20180908

typedef struct st1
{
	unsigned char a;
	//unsigned int c;
	//unsigned short b;
}_st1;

typedef struct st2
{
	unsigned char a:1;
	unsigned int c:5;
	char *p;
	unsigned short b;
}_st2;

typedef struct st3
{
	_st1 *s1;
	_st2 s2;
	unsigned char a;
	unsigned long b;
}_st3;

int main( int argc, char*argv[ ])
{
	int i0 = 5, j0 = 5, p0 = 0, q0 = 0;
	p0 = (i0++)+(i0++)+(i0++);
	q0 = (++j0)+(++j0)+(++j0);

	printf("p: %d, q: %d, i: %d, j: %d.\r\n", p0,q0,i0,j0);
	
	char sup[4] = {0};

	char *aa = "1234567890";

	unsigned int a = 4, b = 5;

	printf("%d, %u\r\n", a-b, a-b);

	snprintf(sup, 4, "%.3s", aa);

	printf("aaa%saaa\n", sup);


	printf("------------------------------------------\r\n");

	_st1 s1;
	_st2 s2;
	_st3 s3;
	char *p;
	printf("sizeof(s1)=%d sizeof(s2)=%d sizeof(s3)=%d\n", sizeof(s1), sizeof(s2), sizeof(s3));
	printf("sizeof(*p)=%d\r\n", sizeof(p));

	int i = 1;
	i = i << 31;
	int k = i+1;
	int j = -1;
	printf("i: %d, %x\n", i, i);
	printf("j: %d, %x\n", j, j);
	printf("k: %d, %x\n", k, k);

	return 0;
}
