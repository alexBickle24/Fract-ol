
#include <stdio.h>
#include <limits.h>

int main(void)
{
	double a;
	double b;
	double c;

	a = 3;
	b = 2;
	c = a / b;
	printf("el resultado es : %lf\n", c);
	printf("%d\n", __SIZEOF_DOUBLE__);
	return (0);
}