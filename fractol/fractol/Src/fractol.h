/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 06:03:56 by alex              #+#    #+#             */
/*   Updated: 2025/03/27 01:26:42 by alex             ###   ########.fr       */
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

typedef struct	s_mlx_enviroment
{
	void				*mlx_var;//lo que devuelve mlx.init
	void				*windows;//lo que devuelve 
	t_image_data		*img_data;
	t_window_data		*win_data;
}				t_mlx_enviroment;

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
	int		endian;//se puede modificar en un sentido u otro (big endian vs little endian)
	void	(*set_def)(t_mlx_enviroment *, t_image_data, int, int);//el puntero a la funcion que define el conjunto que se va a renderizar
	char	**config;//los argumentos de ese conjuntos para hacer variaciones desde la ejecucion
	int		max_iter;//para la precision de los fractales (mas iteraciones == a mas precision en el calculo de colores)
	int		color;//todavia no se como configurarlo la idea es mandar los colores desde los argumentos para que funcioe de maneras diferentes
	double	zoom;//para establecer los valores de zoom desde el argumento del programa
	int		origin[2];//para establecer el origen de la imagen desde el argumento del programa
	int		with;//para establece
}				t_image_data;

typedef struct	s_complex_factors
{
	double		a;//parte real
	double		b;//parte imaginaria
}	t_complex_factors;


//si puediese usar globales tendria sentido
// typedef struct	s_set_select
// {
// 	char	*name;
// 	int		argz;
// 	char	**args;
// 	int		(*f)(t_mlx_utils *, t_image_data, int, int);
// 	t_set_select	*next_set;
// }				t_set_select;


///////////////////////////***Prototipes***////////////////////////

//SETS
void		mandelbrot_set(t_mlx_utils *mlx, t_image_data *img);
void		julia_set(t_mlx_utils *mlx, t_image_data *img);

//SET_MLX_ENVIROMENT_TO_RENDER
t_mlx_utils	*setup_mlx_enviroment(t_image_data **image);

//SET IMAGE
char		select_image_to_render(t_mlx_utils *mlx, char **argv, int argz);
char		**load_args_table(int num_args, char **argv);

//RENDER
void		render_set(t_mlx_utils *mlx, t_image_data *image, int (*set_pixel)(t_mlx_utils *, t_image_data*, int, int));
void		xy_to_image_coords(t_complex_factors *z, int x, int y);
void		apply_zoom_and_moves(t_complex_factors	*z, int	x, int y);
void		mlx_put_image_to_window(/**/);//cambiar mlx_data por mlx enviroment.

//MATHS


//MANAGE EVENTS


//UTILS
void		ft_error(char *message);
double		atodbl(char *str);


#endif