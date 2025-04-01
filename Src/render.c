/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:47 by alex              #+#    #+#             */
/*   Updated: 2025/04/01 20:11:24 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scale_xy_to_image_coords(t_complex_factors *z, int x, int y, t_image_data *img)
{
	double scale_x = (double)(MAND_MAX_X - MAND_MIN_X) / (WIDTH - 0);
	double scale_y = (double)(MAND_MAX_Y - MAND_MIN_Y) / (HEIGHT - 0);
	double adjusted_x = (double)(x - img->origin[0]);
	double adjusted_y = (double)(y + img->origin[1]);

	printf("scale_x: %f, scale_y: %f\n", scale_x, scale_y);
	printf("adjusted_x: %f, adjusted_y: %f\n", adjusted_x, adjusted_y);

	z->real = adjusted_x * scale_x;
	z->imaginary = adjusted_y * scale_y;

	printf("z->real: %f, z->imaginary: %f\n", z->real, z->imaginary);
	// sleep(2);
}
void		apply_zoom_and_moves(t_complex_factors	*z, t_image_data *img)
{
	printf("Before zoom and moves:\n");
	printf("z->real: %f, z->imaginary: %f\n", z->real, z->imaginary);
	printf("img->zoom: %f, img->with[0]: %f, img->with[1]: %f\n", img->zoom, img->with[0], img->with[1]);

	z->real = (z->real / img->zoom) + img->with[0];
	z->imaginary = (z->imaginary / img->zoom) + img->with[1];

	printf("After zoom and moves:\n");
	printf("z->real: %f, z->imaginary: %f\n", z->real, z->imaginary);
}

void		buffering_pixel(int x, int y, t_image_data *img, int color)
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
	static int debug;

	printf("llega dsadaRENDERdasdsadaqui\n");
	x = -1 ;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			printf("render 1\n");
			scale_xy_to_image_coords(&z, x, y, image);
			apply_zoom_and_moves(&z, image);
			printf("render 2\n");
			pixel_color = image->set_def(image, &z);
			buffering_pixel(x, y, image, pixel_color);
			debug++;
			printf("\n\nel valor de debug es: %d\n", debug);
		}
	}
	mlx_put_image_to_window(mlx->mlx_var, mlx->window, image, x, y);
}
