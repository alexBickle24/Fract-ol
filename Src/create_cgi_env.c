/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cgi_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:09:46 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 08:46:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	select_set_to_render(t_image_data *img, char **argv, int argz)
{
	if (ft_strncmp(argv[1], "Mandelbroot", 10) && ft_strlen(argv[1]))
	{
		if (argz > 2)
			return (ft_putstr_fd("Too many arguments for Mandelbrot\n", 2), 0);
		img->name = "Mandelbrot";
		img->set_def = mandelbrot_set;
		img->config = load_args_table(argz - 2, argv);
	}
	else if (ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]))
	{
		if(argz != 4)
			return (ft_putstr_fd("You need 4 arguments for Julia\n", 2), 0);
		img->name = "Julia";
		img->set_def = julia_set;
		img->config = load_args_table(argz - 2, argv);
	}
	else
		return (ft_putstr_fd("You have to chose Mandelbrot or Julia\n", 2), 0);
}

char	setup_mlx_enviroment(t_mlx_enviroment *mlx, t_image_data *img)
{
	if (!mlx)
		return (0);
	mlx->mlx_var = mlx_init();
	if (!mlx->mlx_var)
		return (0);
	mlx->window = mlx_new_window(mlx->mlx_var, WIDTH, HEIGHT, img->name);
	if (!mlx->window)
		return (/*free_window and free mlx_va*/0);
	img->img_var = mlx_new_image(mlx->mlx_var, HEIGHT, WIDTH);
	if (!img->img_var)
		return (/*free_window and free mlx_va and imag*/0);
	img->bit_map_address = mlx_get_data_addr(img->img_var, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	if (!img->bit_map_address)
		return (/*free_window and free mlx_va and imag*/0);
	//aqui va mlx events init (porque va a aqui)	
	set_default_values(img);
	mlx->img_data = img;
	return (1);
}

void	set_default_values(t_image_data *img)
{
	int	origin_x;
	int	origin_y;
	
	if (WIDTH % 2 != 0)
		origin_x = WIDTH / 2;
	else 
		origin_x = (WIDTH / 2) + 1;
	if (HEIGHT % 2 != 0)
		origin_x = HEIGHT / 2;
	else 
		origin_x = (WIDTH / 2) + 1;
	img->origin[0] = origin_x;
	img->origin[1] = origin_y;
	img->with[0] = 0;
	img->with[1] = 0;
	img->zoom = 1;
	img->max_iter = 42;
}

//1.-init mlx events 


//2.- Julia track
//porque hay que se usar este evento y pra que se usa.