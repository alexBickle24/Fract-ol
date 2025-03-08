/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/03/07 21:42:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_utils		*mlx;
	t_image_data	*image;
	int				(*f)[2];
	
	parse_argumets(image, (*f), 
	// if (argc == 2)
	// {
	// 	if (ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]))
	// 	{
	// 		// do_mandelbrot();//TO DO;
	// 		printf("mandelbrot\n");
	// 	}
	// 	else if (ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]))
	// 	{
	// 		// do_julia();//TO DO
	// 		printf("julia\n");
	// 	}
	// 	else
	// 	{
	// 		printf("no valid argument name\n");
	// 		return(1);
	// 	}
		if ((mlx = setup_mlx_enviroment(&image)) == NULL)
			return (1)
		render_fractol(mlx, image);
		mlx_loop(mlx->mlx_data);

		return (0);
	// }

}


t_mlx_utils	*setup_mlx_enviroment(t_image_data **image)
{
	t_mlx_utils		*mlx;

	mlx->mlx_data = mlx_init();
	if (!mlx->mlx_data)
	{
		return (NULL);
	}
	mlx->windows = mlx_new_window(mlx->mlx_data, mlx->win_data->height, mlx->win_data->height, "Fractol");
	if (!mlx->windows)
	{
		//free_window 
		return (NULL);
	}
	image[0]->img = mlx_new_image(mlx->mlx_data, HEIGHT, WIDTH);
	if (!image[0]->img)
	{
		//free_image and window
		return (NULL);
	}
	mlx->img_data->bit_map_address = mlx_get_data_addr(image[0]->img, &mlx->img_data->bits_per_pixel, &mlx->img_data->line_length, &mlx->img_data->endian);
	if (!mlx->img_data->bit_map_address)
	{
		//freee image and window
		return (NULL);
	}
	
}

void	render_set(t_mlx_utils *mlx, t_image_data *image, int (*set_pixel)(t_mlx_utils *, t_image_data*, int, int))
{
	t_complex_data	*z;
	int				pixel_color;
	int 			x;
	int 			y;

	x = -1 ;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			scale_xy_to_image_coords(&z, x, y);
			apply_zoom_and_moves()
			pixel_color = set_pixel(mlx, image, z->a, z->b);
			buffer_my_pixel(z->a, z->b, image->bit_map_address, pixel_color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_data, mlx->windows, image, x, y);//cambiar mlx_data por mlx enviroment.
}

void	xy_to_image_coords(t_complex_data *z, int x, int y)
{
	double	origin_x;
	double	origin_y;
	
	origin_x = (WIDTH / 2);
	origin_y = (HEIGHT / 2);
	z->a = (x - origin_x) * ((MAND_MAX_X - MAND_MIN_X) / (WIDTH - 0));
	z->b = (y - origin_y) * ((MAND_MAX_Y - MAND_MIN_Y) / (HEIGHT - 0));
}

int	fmandelbroot_set(t_mlx_utils *mlx, t_image_data *imag, double a, double b)
{
	// if (!imag->config)
	// {
	// 	return (0);
	// }
	
}