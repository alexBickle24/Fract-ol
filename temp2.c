

#include <stdio.h>
#include <string.h>

size_t	ft_power_of(size_t  num, int power);

double	ft_atodbl(const char *nptr)
{
	long	sing;
	long	num;
	int		div;//
	int		point_control;//
	int		i;
	double	result;//

	sing = 1;
	num = 0;
	point_control = 0;
	i = 0;//
	div = 0;//
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sing = -1;
		i++;
	}
	if (nptr[i] == '.')
		return (0);
	//esto lo puedo meter en una funcion.
	while (((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.'))
	{
		if (nptr[i] == '.' && point_control == 0)
			(div = i, point_control = 1);
		else if (point_control == 1 && nptr[i]== '.')
			return (0);
		else 
			num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (div == 0)
		return (num * sing);
	result = (double)num / (double)ft_power_of(10, strlen(nptr + div) - 1);
	return (result * sing);
}


size_t	ft_power_of(size_t  num, int power)
{
	size_t	n_square;
	int		i;
	
	if (power < 0)
		return (0);
	if(power == 0)
		return (1);
	if (power == 1)
		return (num);
	if (power == 2)
		return (n_square = num * num);
	n_square = num * num;
	i = 1;
	while (i < power)
	{
		n_square = n_square * num;
		i++;
	}
	return (n_square);
}

int main(void)
{
	double result;

	result = ft_atodbl("33333.2");
	printf("el valor del resultado es %lf\n", result);
}