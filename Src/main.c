/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:08:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argz, char **argv)
{
	t_mlx_enviroment	mlx;
	t_image_data		img_data;
	
	if (argz < 2)
		ft_error("Need more arguments\n");
	select_image_to_render(&img_data, argv, argz);
	if (!setup_mlx_enviroment(&mlx, &img_data))
		return (1);
	render_set(&mlx, mlx.img_data);
	mlx_loop(mlx.mlx_var);
	return (0);
}





































