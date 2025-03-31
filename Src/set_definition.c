/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_definition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:59:27 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:07:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	*c;
	int					i;
	int					color;
	 
	c->real = z->real;
	c->imaginary = z->imaginary;
	i = 0;
	while (i < img->max_iter)
	{
		z->real = ft_power(z->real, 2) - ft_power(z->imaginary, 2);
		z->imaginary = 2 * z->real + z->imaginary;
		if (!mand_jul_coords_necesary_conditions(z->real, z->imaginary))
		{
			if (i == img->max_iter - 1)
				return (GOLD);
			return (get_color_from_palethe(i, img->max_iter));
		}
	}
	return (BLACK);
}

void	julia_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	*c;
	int					i;
	int					color;
	
 
	c->real = ft_atodbl(img->config[0]);
	c->imaginary = ft_atodbl(img->config[1]);
	i = 0;
	while (i < img->max_iter)
	{
		z->real = ft_power(z->real, 2) - ft_power(z->imaginary, 2);
		z->imaginary = 2 * z->real + z->imaginary;
		if (!mand_jul_coords_necesary_conditions(z->real, z->imaginary))
		{
			if (i == img->max_iter - 1)
				return (GOLD);
			return (get_color_from_palethe(i, img->max_iter));
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