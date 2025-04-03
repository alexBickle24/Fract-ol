/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/04/03 13:10:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argz, char **argv)
{
	t_mlx_enviroment	mlx;
	t_image_data		img_data;

	if (argz < 2)
	{
		ft_putstr_fd("Need more arguments\n", 2);
		exit (0);
	}
	if (!select_set_to_render(&img_data, argv, argz))
		return (1);
	if (!setup_mlx_enviroment(&mlx, &img_data))
		return (1);
	render_set(&mlx, &img_data);
	mlx_loop(mlx.mlx_var);
	return (0);
}
