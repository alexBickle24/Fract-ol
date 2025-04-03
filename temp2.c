

#include <stdio.h>
#include <string.h>

size_t	ft_power_of(size_t  num, int power);
static double ft_atodbl_aux(char *nptr, int *i, int sing);

double	ft_atodbl(const char *nptr)
{
    long	sing;
    int		i;

    sing = 1;
    i = 0;
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
    return (ft_atodbl_aux((char *)nptr, &i, sing));
}

static double ft_atodbl_aux(char *nptr, int *i, int sing)
{
    long	num;
    int		point_control;
    double	result;
    int		div;

    point_control = 0;
    num = 0;
    div = -1;
    while ((nptr[*i] >= '0' && nptr[*i] <= '9') || nptr[*i] == '.')
    {
        if (nptr[*i] == '.' && point_control == 0)
        {
            div = *i; // Guarda la posición del punto decimal
            point_control = 1;
        }
        else if (point_control == 1 && nptr[*i] == '.')
            return (0); // Error: segundo punto decimal
        else
            num = num * 10 + (nptr[*i] - '0');
        (*i)++;
    }
    if (div == -1) // Si no hay punto decimal
        return (num * sing);
    result = (double)num / (double)ft_power_of(10, *i - div - 1);
    return (result * sing);
}

size_t	ft_power_of(size_t num, int power)
{
	size_t	n_square;
	int		i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (num);
	if (power == 2)
		return (num * num);
	n_square = num * num;
	i = 2;
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

	result = ft_atodbl("34");
	printf("el valor del resultado es %lf\n", result);
}


//FUNCIONES PREVIAS ESTA LA VCERSION COMPLETA, LA QUE FALLA , Y LA DIVIDIDA CON ERRROR 
// static long	ft_parse_number(const char *nptr, int *i, int *div,
// 	int *point_control)
// {
// long	num;

// num = 0;
// while ((nptr[*i] >= '0' && nptr[*i] <= '9') || nptr[*i] == '.')
// {
// 	if (nptr[*i] == '.' && *point_control == 0)
// 	{
// 		*div = *i;
// 		*point_control = 1;
// 	}
// 	else if (*point_control == 1 && nptr[*i] == '.')
// 		return (0);
// 	else
// 		num = num * 10 + (nptr[*i] - '0');
// 	(*i)++;
// }
// return (num);
// }

// static double	ft_calculate_result(const char *nptr, long num, int div,
// 	long sing)
// {
// double	result;

// result = (double)num / (double)ft_power_of(10, strlen(nptr + div) - 1);
// return (result * sing);
// }

// double	ft_atodbl(const char *nptr)
// {
// long	sing;
// long	num;
// int		point_control;
// int		i;
// int		div;

// sing = 1;
// num = 0;
// point_control = 0;
// i = 0;
// div = 0;
// while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
// 	i++;
// if (nptr[i] == '-' || nptr[i] == '+')
// {
// 	if (nptr[i] == '-')
// 		sing = -1;
// 	i++;
// }
// if (nptr[i] == '.')
// 	return (0);
// num = ft_parse_number(nptr, &i, &div, &point_control);
// if (div == 0)
// 	return (num * sing);
// return (ft_calculate_result(nptr, num, div, sing));
// }


//division que no funcoin

// double	ft_atodbl(const char *nptr)
// {
// 	long	sing;
// 	long	num;
// 	int		div;
// 	int		point_control;
// 	int		i;
// 	double	result;

// 	sing = 1;
// 	num = 0;
// 	point_control = 0;
// 	i = 0;
// 	div = -1; // Initialize div to -1 to indicate no decimal point initially
// 	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			sing = -1;
// 		i++;
// 	}
// 	if (nptr[i] == '.')
// 		return (0);
// 	while ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.')
// 	{
// 		if (nptr[i] == '.' && point_control == 0)
// 		{
// 			div = i; // Store the position of the decimal point
// 			point_control = 1;
// 		}
// 		else if (point_control == 1 && nptr[i] == '.')
// 			return (0);
// 		else
// 			num = num * 10 + (nptr[i] - '0');
// 		i++;
// 	}
// 	if (div == -1) // If no decimal point was found
// 		return (num * sing);
// 	result = (double)num / (double)ft_power_of(10, i - div - 1); // Adjust division based on decimal position
// 	return (result * sing);
// }

// static double ft_atodbl_aux(char *nptr, int *i, int sing);
// size_t	ft_power_of(size_t num, int power);

// double	ft_atodbl(const char *nptr)
// {
// 	long	sing;
// 	// long	num;//
// 	// int		div;//
// 	// int		point_control;//
// 	int		i;
// 	// double	result;//

// 	sing = 1;//
// 	// num = 0;
// 	// point_control = 0;//
// 	i = 0;
// 	// div = -1; // Initialize div to -1 to indicate no decimal point initially
// 	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
// 		i++;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			sing = -1;
// 		i++;
// 	}
// 	if (nptr[i] == '.')
// 		return (0);
// 	return (ft_atodbl_aux((char *)nptr, &i, sing));
// }

// static double ft_atodbl_aux(char *nptr, int *i, int sing)
// {
// 	long	num;
// 	int		point_control;
// 	double	result;
// 	int		div;

// 	point_control = 0;
// 	while ((nptr[*i] >= '0' && nptr[*i] <= '9') || nptr[*i] == '.')
// 	{
// 		if (nptr[*i] == '.' && point_control == 0)
// 		{
// 			div = *i; 
// 			point_control = 1;
// 		}
// 		else if (point_control == 1 && nptr[*i] == '.')
// 			return (0);
// 		else
// 			num = num * 10 + (nptr[*i] - '0');
// 		i++;
// 	}
// 	if (div == -1) 
// 		return (num * sing);
// 	result = (double)num / (double)ft_power_of(10, *i - div - 1);
// 	return (result * sing);
// }