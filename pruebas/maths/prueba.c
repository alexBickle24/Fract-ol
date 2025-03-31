
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a;
	int b;
	double c;
	int d;
	double e;

	a = 30000;
	b = 28;
	c = (double)a / (double)b;
	d = (int)c;
	e = (double)d;
	printf("el resultado es : %lf\n", c);
	printf("el resultado es : %d\n", d);
	printf("el resultado es : %lf\n", e);
	// printf("%d\n", );
	return (0);
}

//cuando dicido dos doubles, si que dan los numeros con decimales 
//cuando divido dos int m,e los sin decimales aunque iguale a un double (creo que es por lo s bits, mirar)
//

// factor = (42 / (double)max_i);
// 	i = factor * (double)i;