#include <stdio.h>

int main( int argc, char*argv[ ])
{
	int j0 = 5, q0 = 0;
	q0 = (++j0)+(++j0)+(++j0);

	printf("p: %d, q: %d.\r\n", q0,j0);
	
	return 0;
}
