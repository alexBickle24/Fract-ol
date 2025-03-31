/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:58:19 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 05:06:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_power_of(size_t  num, int power)
{
	size_t	n_square;
	int		i;

	n_square = num * num;
	i = 1;
	while (i < power)
	{
		n_square = n_square * num;
		i++;
	}
	return (n_square);
}



//forma uno dividiendo la parte entera y la decimal y concatenando y sumando 
// void	ft_atobl(char *str)
// {
// 	int		i;
// 	char	*int_part_str;
// 	double	int_part_double;

// 	i = 0;
// 	while (str[i] && str[i] != '.')
// 		i++;
// 	int_part_str = ft_substr(str, 0, i);
// 	if (!int_part_double)
// 		return ;
// 	int_part_double= ft_atoi(int_part_str);
	
// 	//free(int_part_double);
// }

//forma dos, directamente convertie el nuero
// void	ft_atobl(char *str)
// {
// 	int		i;
// 	char	*int_part_str;
// 	double	int_part_double;

// 	i = 0;
// 	while (str[i] && str[i] != '.')
// 	{
		
// 		i++;
// 	}
// 	int_part_str = ft_substr(str, 0, i);
// 	if (!int_part_double)
// 		return ;
// 	int_part_double= ft_atoi(int_part_str);
	
// 	//free(int_part_double);
// }