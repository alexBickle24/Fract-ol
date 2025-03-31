/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:07:47 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 05:07:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void mlx_put_image_to_window(mlx->mlx_data, mlx->windows, image, x, y);//cambiar mlx_data por mlx enviroment.
void	xy_to_image_coords(t_complex_factors *z, int x, int y)
{
	double	origin_x;
	double	origin_y;
	
	origin_x = (WIDTH / 2);
	origin_y = (HEIGHT / 2);
	//los mivimeintos sobre la pantalla los voy a tener que meter antes de aplicar el algoritmo y el escalado
	z->real = (x - origin_x) * ((MAND_MAX_X - MAND_MIN_X) / (WIDTH - 0));
	z->imaginary = (y - origin_y) * ((MAND_MAX_Y - MAND_MIN_Y) / (HEIGHT - 0));
	//o los meto despues del escalado conuna relacion
}

void		apply_zoom_and_moves(t_complex_factors	*z, int	x, int y)
{
	
}

void	render_set(t_mlx_enviroment *mlx, t_image_data *image, int (*set_pixel)(t_mlx_enviroment *, t_image_data*, int, int))
{
	t_complex_factors	*z;
	int					pixel_color;
	int 				x;
	int 				y;
	struct 				mlx_col_name[];

	x = -1 ;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			scale_xy_to_image_coords(&z, x, y);
			apply_zoom_and_moves(z, x, y);
			pixel_color = set_pixel(mlx, image, z->real, z->imaginary);
			buffer_my_pixel(z->real, z->imaginary, image->bit_map_address, pixel_color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_var, mlx->window, image, x, y);//cambiar mlx_data por mlx enviroment.
}

void buffer_my_pixel();

