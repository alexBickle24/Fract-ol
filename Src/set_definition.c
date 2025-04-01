/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_definition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:59:27 by alex              #+#    #+#             */
/*   Updated: 2025/04/01 20:07:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_set(t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	c;
	int					i;
	 
	printf("ENTRA EN MANDELBROT SET\n");
	c.real = z->real;
	c.imaginary = z->imaginary;
	i = 0;
	printf("%d\n",img->max_iter);
	while (i < img->max_iter)
	{
		z->real = (power_of(z->real, 2) - power_of(z->imaginary, 2)) + c.real;
		z->imaginary = (2 * z->real + z->imaginary) + c.imaginary;
		if (!mand_jul_coords_necesary_conditions(z->real, z->imaginary))
		{
			// if (i == img->max_iter - 1)
			return (GOLD);
			// return (get_color_from_palethe(i, img->max_iter));
		}
		i++;
	}
	return (BLACK);
}

int		julia_set(t_image_data *img, t_complex_factors *z)
{
	t_complex_factors	c;
	int					i;
	
	c.real = ft_atodbl(img->config[0]);
	c.imaginary = ft_atodbl(img->config[1]);
	i = 0;
	printf("%d\n",img->max_iter);
	sleep(1);
	while (i < img->max_iter)
	{
		z->real = (power_of(z->real, 2) - power_of(z->imaginary, 2)) + c.real;
		z->imaginary = (2 * z->real + z->imaginary) + c.imaginary;
		if (!mand_jul_coords_necesary_conditions(z->real, z->imaginary))
		{
			if (i == img->max_iter - 1)
				return (GOLD);
			return (get_color_from_palethe(i, img->max_iter));
		}
		i++;
	}
	return(BLACK);
}

char	mand_jul_coords_necesary_conditions(double real, double imaginary)
{
	if ((power_of(real, 2) + power_of(imaginary, 2)) > 4)
		return (0);
	return (1);
}