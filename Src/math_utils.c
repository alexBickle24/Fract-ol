/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:58:19 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:09:07 by alex             ###   ########.fr       */
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
