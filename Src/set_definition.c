/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_definition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:59:27 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 01:38:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	*c;
	int					i;
	int					color;
	
	//al ser mandelbroot el valor inicial de "c", es igual a los valores iniciales de 
	c->real = z->real;
	c->imaginary = z->imaginary;
	//funcion de algoritmo de escalado
	i = 0;
	while (i < img->max_iter)
	{
		z->real = ft_power(z->real, 2) - ft_power(z->imaginary, 2);
		z->imaginary = 2 * z->real + z->imaginary;
		if (ft_power(z->real, 2) + t_power(z->imaginary, 2) > 4)
		{
			color = 
			return ;
		}
	}
	color = BLACK;
	return ;
}

void	julia_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	*c;
	int					i;
	int					color;
	
	//al ser mandelbroot el valor inicial de "c", es igual a los valores iniciales de 
	c->real = z->real;
	c->imaginary = z->imaginary;
	//funcion de algoritmo de escalado
	i = 0;
	while (i < img->max_iter)
	{
		z->real = ft_power(z->real, 2) - ft_power(z->imaginary, 2);
		z->imaginary = 2 * z->real + z->imaginary;
		if (!mand_jul_coords_necesary_conditions(z->real, z->imaginary))
		{
			if (i == img->max_iter - 1)
				return (GOLD);
			return ;
		}
	}
	return(BLACK);
}

char	mand_jul_coords_necesary_conditions(double real, double imaginary)
{
	if (power_of_bool(real, 2) + power_of_bool(imaginary, 2) > 4)
		return (0);
	return (1);
}