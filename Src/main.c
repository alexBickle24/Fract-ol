/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 05:13:15 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argz, char **argv)
{
	t_mlx_enviroment	mlx;
	
	//parseo de limitees
	if (argz < 2)
		ft_error("Need more arguments\n");
	//seleccionar imagen segun argumentos;
	select_image_to_render(mlx.img_data, argv, argz);
	//conectar con API, crear ventana y crear objeto imagen.
	if ((mlx = setup_mlx_enviroment(&(mlx.img_data))) == NULL)
		return (1);
	//renderizar el set que queramos representar
	render_set(mlx, mlx.img_data, mandelbrot_set);
	//mantener el programa en ejecucion hasta que evento (API X11) lo pare.
	mlx_loop(mlx.mlx_var);
	return (0);
}





































