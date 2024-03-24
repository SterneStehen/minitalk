#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a;
	int b;
	int n = 16;
	
	a = n >> 3;
	b = n / 8;

	a = n << 3;
	b = n * 8;

    printf("shift = %d\n", a);
	printf("multiplay = %d\n", b);
}