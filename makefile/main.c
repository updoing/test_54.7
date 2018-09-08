
#include <stdio.h>
#include "common.h"
#include "decode/decode.h"

int main(int argc, char *agv[])
{
	printf("%s[%s: %d]...\n", __FILE__, __func__, __LINE__);

	common(15, 3);

	char str[] = "hello world";
	decode(str);

	return 0;
}

