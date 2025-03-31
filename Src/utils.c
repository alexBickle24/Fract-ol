/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:13:38 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:08:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atodbl(const char *nptr)
{
	long	sing;
	long	num;
	int		div;
	int		i;
	double	result;
	int		point_control;

	sing = 1;
	num = 0;
	point_control = 0;
	i = 0;
	div = 0;
	while ((nptr[i] == 32 || (nptr[i] >= 9) && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sing = -1;
		i++;
	}
	if (nptr[i] == '.')
		return (0);
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
	printf("num es : %ld\n", num);
	if (div == 0)
		return (num * sing);
	result = (double)num / (double)ft_power_of(10, 3-1);
	return (result * sing);
}

char	**load_args_table(int num_args, char **argv)
{
	char	**table_args;
	int		i;
	
	if (num_args == 0)
		return (NULL);
	table_args = (char **)malloc(sizeof(char *) * num_args);
	if (!table_args)
		return (NULL);
	i = 1;
	while (i < (num_args - 1) || argv[i] != NULL)
	{
		table_args[i] = argv[i];
		i++;
	}
	return (table_args);
}

void	ft_error(char *message)
{
	if (!message)
		return ;
	ft_putstr_fd(message, 2);
	return (1);	
}