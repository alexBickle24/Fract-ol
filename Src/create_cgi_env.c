/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cgi_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:09:46 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:09:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	setup_mlx_enviroment(t_mlx_enviroment *mlx, t_image_data *img)
{
	
	if (!mlx)
		return (0);
	mlx->mlx_var = mlx_init();
	if (!mlx->mlx_var)
		return (0);
	mlx->window = mlx_new_window(mlx->mlx_var, WIDTH, HEIGHT, "Fractol");
	if (!mlx->window)
		return (/*free_window and free mlx_va*/0);
	img->img_var = mlx_new_image(mlx->mlx_var, HEIGHT, WIDTH);
	if (!img->img_var)
		return (/*free_window and free mlx_va and imag*/0);
	img->bit_map_address = mlx_get_data_addr(img->img_var, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	if (!img->bit_map_address)
		return (/*free_window and free mlx_va and imag*/0);
	set_default_values(img);
	mlx->img_data = img;
	return (1);
}
char	select_set_to_render(t_image_data *img, char **argv, int argz)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]))
	{
		if (argz > 2)
			return (ft_putstr_fd("Too many arguments for Mandelbroot\n", 2), 0);
		img->set_def = mandelbrot_set;
		img->config = load_args_table(argz - 2, argv);
	}
	else if (ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]))
	{
		if(argz != 4)
			return (ft_putstr_fd("ERROR, you need 4 arguments for Julia\n", 2), 0);
		img->set_def = julia_set;
		img->config = load_args_table(argz - 2, argv);
	}
	else
		return (ft_putstr_fd("you have to choose Mandelbroor or Julia\n", 2), 0);
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
	img->with[0] = 1;
	img->with[1] = 1;
	img->zoom = 1;
	img->max_iter = 42;
}