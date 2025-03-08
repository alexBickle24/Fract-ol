/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 06:03:56 by alex              #+#    #+#             */
/*   Updated: 2025/03/07 20:56:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include "../include/libft/libft.h"
#include "../include/Minilibx/mlx.h"
#include "../include/Minilibx/mlx_int.h"
// #include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define MAND_MAX_X 2
#define MAND_MIN_X -2
#define MAND_MAX_Y 2
#define MAND_MIN_Y -2


///////////////////////////***Structs***///////////////////////////

typedef struct	s_mlx_utils
{
	void				*mlx_data;//lo que devuelve mlx.init
	void				*windows;//lo que devuelve 
	t_image_data		*img_data;
	t_window_data		*win_data;
}				t_mlx_utils;

typedef struct	s_window_data//se podrian usar tambien defines y flags para modificarlo abra que destruit y abrir ventanas
{
	int				width;
	int				height;
	t_window_data	*next;
}				t_window_data;

typedef struct	s_image_data
{
	void	*img;//lo que devuelve mlx_new_image
	char	*bit_map_address;//lo que devuelve mlx_get_data_addr
	int		bits_per_pixel;//para saber cuantos bits hay en un pixel
	int		line_length;//para saber cuantos bytes hay en una fila de la imagen
	int		endian;//se puede modificar en un sentido u otro
	int		(*set_def)(t_mlx_utils *, t_image_data, int, int);
	char	**config;
	int		max_iter;//para la precision de los fractales
	int		color;//todavia no se como configurarlo la idea es mandar los colores desde los argumentos para que funcioe de maneras diferentes
	double	zoom;//para establecer los valores de zoom desde el argumento del programa
	int		origin[2];//para establecer el origen de la imagen desde el argumento del programa
	int		with;//para establece
}				t_image_data;

typedef struct	s_complex_data
{
	double		a;//parte real
	double		b;//parte imaginaria
}				t_complex_data;

typedef struct	s_set_select
{
	char	*name;
	int		argz;
	char	**args;
	int		(*f)(t_mlx_utils *, t_image_data, int, int);
	t_set_select	*next_set;
}				t_set_select;


///////////////////////////***Prototipes***////////////////////////


#endif