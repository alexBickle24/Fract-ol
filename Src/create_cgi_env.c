/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cgi_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:09:46 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 05:08:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx_enviroment	*setup_mlx_enviroment(t_mlx_enviroment	**mlx, t_image_data **img)
{
	if (!mlx)
		return (NULL);
	mlx[0]->mlx_var = mlx_init();
	if (!mlx[0]->mlx_var)
		return (NULL);
	mlx[0]->window = mlx_new_window(mlx[0]->mlx_var, WIDTH, HEIGHT, "Fractol");
	if (!mlx[0]->window)
		return (/*free_window and free mlx_va*/NULL);
	img[0]->img_var = mlx_new_image(mlx[0]->mlx_var, HEIGHT, WIDTH);
	if (!mlx[0]->img_data->img_var)
		return (/*free_window and free mlx_va and imag*/NULL);
	img[0]->bit_map_address = mlx_get_data_addr(img[0]->img_var, img[0]->bits_per_pixel, img[0]->line_length, img[0]->endian);
	if (img[0]->bit_map_address)
		return (/*free_window and free mlx_va and imag*/NULL);
}
char	select_image_to_render(t_mlx_enviroment *mlx, char **argv, int argz)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]))
	{
		if (argz > 2)
		{
			ft_putstr_fd("Too many arguments for Mandelbrot\n", 2);
			return (0);
		}
		mlx->img_data->set_def = mandelbrot_set;
		mlx->img_data->config = load_args_table(argz - 2, argv);
	}
	else if (ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]))
	{
		if( /*argz == n*/)
		{
			ft_putstr_fd("ERROR, you need x arguments ofr Julia\n", 2);
			return (0);
		}
		mlx->img_data->set_def = julia_set;
		mlx->img_data->config = load_args_table(argz - 2, argv);
	}
	else
	{
		ft_putstr_fd("you have to choose Mandelbroor or Julia\n", 2);
		return (0);
	} 
}
