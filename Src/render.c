/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:47 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:06:09 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	xy_to_image_coords(t_complex_factors *z, int x, int y, t_image_data *img)
{
	//los mivimeintos sobre la pantalla los voy a tener que meter antes de aplicar el algoritmo y el escalado
	z->real = (x - img->origin[0]) * ((MAND_MAX_X - MAND_MIN_X) / (WIDTH - 0));
	z->imaginary = (y - img->origin[1]) * ((MAND_MAX_Y - MAND_MIN_Y) / (HEIGHT - 0));
	//o los meto despues del escalado conuna relacion
}

void		apply_zoom_and_moves(t_complex_factors	*z, t_image_data *img)
{
	z->real = (z->real / img->zoom) + img->with[0];
	z->imaginary = (z->imaginary / img->zoom) + img->with[1];
}

void		buffer_my_pixel(int x, int y, t_image_data *img, int color)
{
	unsigned int offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->bit_map_address + offset) = color;
	
}

void	render_set(t_mlx_enviroment *mlx, t_image_data *image)
{
	t_complex_factors	z;
	int					pixel_color;
	int 				x;
	int 				y;

	x = -1 ;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			scale_xy_to_image_coords(&z, x, y);
			apply_zoom_and_moves(&z, image);
			pixel_color = set_pixel(mlx, image, z.real, z.imaginary);
			buffer_my_pixel(x, y, &image, pixel_color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_var, mlx->window, image, x, y);//cambiar mlx_data por mlx enviroment.
}
