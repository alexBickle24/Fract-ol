/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/03/05 16:18:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_square(int x_origin, int y_origin, void *mlx, int width, int height, void *win);
static void	my_pixel_put(int x, int y, t_img *img, int color);
int	main(int argc, char **argv)
{
	void 	*mlx;
	void	*win;
	t_data	fractol_data;
	
	(void)argv;
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]))
		{
			// do_mandelbrot();//TO DO;
			printf("mandelbrot\n");
		}
		else if (ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]))
		{
			// do_julia();//TO DO
			printf("julia\n");
		}
		else
		{
			printf("no valid argument name\n");
			return(1);
		}
		//////////////////////////////////
		mlx = mlx_init();
		if (mlx == NULL)
		{
			printf("error\n");
			return (1);
		}
		printf("mlx_init() success\n");
		win = mlx_new_window(mlx, 800, 600, "hola");
		if (win == NULL)
		{
			printf("error\n");
			return (1);
		}
		fractol_data.img = mlx_new_image(mlx, 800, 600);
		fractol_data.addr = mlx_get_data_addr(fractol_data.img, &(fractol_data.bits_per_pixel), 
						&(fractol_data.line_length), &(fractol_data.endian));
		// paint_square(0, 0, mlx, 500, 500, win);
		my_pixel_put(0, 0, (t_img *)&fractol_data.img, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, &fractol_data.img, 500, 500);
		// // paint_square(0, 0, mlx, 800, 550, win);
		// sleep(2);
		// paint_square(0, 0, mlx, 800, 550, win);
		mlx_loop(mlx);
		// return (0);
		return (0);
	}
	// else 
		/*mensaje de error configirado por errno*/
	// return (0);
	// (void
}

void	paint_square(int x_origin, int y_origin, void *mlx, int width, int height, void *win)
{
	int	i;
	
	i = height;
	while (--width)
	{
		height = i;
		while (--height)
		{
			mlx_pixel_put(mlx, win, x_origin+width, y_origin+height, 0x0000FF00 + width);
		}
	}
}

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->height) + (x * (img->bpp / 8));
	*(unsigned int *)(img->data + offset) = color;
}

