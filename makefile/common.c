#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "multi.h"

int common(int a, int b)
{
	int c = 0, d = 0, e = 0;
	c = add(a, b);
	d = sub(a, b);
	e = multi(c, d);
	printf("result: %d\n", e);
	return 0;
}
