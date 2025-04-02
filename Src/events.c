/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:43:31 by alex              #+#    #+#             */
/*   Updated: 2025/04/02 13:15:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//1.-tipos de eventos funcion 
int		manage_key(int keysym, t_mlx_enviroment *mlx)
{
	char	happend;
	
	happend = 0;
	if (keysym == XK_Escape)
		close_handler(mlx);
	if (keysym == XK_plus || keysym == XK_KP_Add)
		(mlx->img_data->max_iter += 10, happend = 1);
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		(mlx->img_data->max_iter -= 10, happend = 1);
	else if (keysym == XK_Left)
		(mlx->img_data->with[0] -= (0.5 / mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Right)
		(mlx->img_data->with[0] += (0.5 / mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Up)
		(mlx->img_data->with[1] -= (0.5 / mlx->img_data->zoom), happend = 1);
	else if (keysym == XK_Down)
		(mlx->img_data->with[1] += (0.5 / mlx->img_data->zoom), happend = 1);
	if (happend)
		render_set(mlx, mlx->img_data);
	return (0);
}

int		manage_mouse(int button, int x, int y, t_mlx_enviroment *mlx)
{
	int	k;

	k = x + y;
	if (button == Button5 && k > INT_MIN)
	{
		mlx->img_data->zoom *= 0.95;
		render_set(mlx, mlx->img_data);
	}
	else if (button == Button4)
	{
		mlx->img_data->zoom *= 1.05;
		render_set(mlx, mlx->img_data);
	}
	return (0);
}

int	close_handler(t_mlx_enviroment *mlx)
{
	//hayq ue hacer que las funciones de cierre de la libreria no hagan segfaukt
	(void)mlx;
	// mlx_destroy_image(mlx->mlx_var,
	// 	mlx->img_data->bit_map_address);
	// mlx_destroy_window(mlx->mlx_var,
	// 	mlx->window);
	// mlx_destroy_display(mlx->mlx_var);
	// free(mlx->mlx_var);
	exit(0);
}
