/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 06:03:56 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 07:02:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include "../include/libft/libft.h"
#include "../include/Minilibx/mlx.h"
#include "../include/Minilibx/mlx_int.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

#define MAND_MAX_X 2
#define MAND_MIN_X -2
#define MAND_MAX_Y 2
#define MAND_MIN_Y -2

#define GOLD 5
#define BLACK 6




///////////////////////////***Structs***///////////////////////////

typedef struct	s_mlx_enviroment
{
	void				*mlx_var;//lo que devuelve mlx.init
	void				*window;//lo que devuelve 
	t_image_data		*img_data;
}				t_mlx_enviroment;

typedef struct	s_image_data
{
	void	*img_var;//lo que devuelve mlx_new_image
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
	int		with[2];//para establece
}				t_image_data;

typedef struct	s_complex_factors
{
	double		real;//parte real
	double		imaginary;//parte imaginaria
}	t_complex_factors;



//SET_MLX_ENVIROMENT_TO_RENDER
char	select_set_to_render(t_image_data *img, char **argv, int argz);
char	*setup_mlx_enviroment(t_mlx_enviroment *mlx, t_image_data *img);
void	set_default_values(t_image_data *img);


//RENDER
void	render_set(t_mlx_enviroment *mlx, t_image_data *image);
void	xy_to_image_coords(t_complex_factors *z, int x, int y, t_image_data *img);
void	apply_zoom_and_moves(t_complex_factors	*z, t_image_data *img);
void	buffer_my_pixel(int x, int y, t_image_data *img, int color);

//SETS
void	mandelbrot_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z);
void	julia_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z);
char	mand_jul_coords_necesary_conditions(double real, double imaginary);

//MATHS
size_t	ft_power_of(size_t  num, int power);

//MANAGE EVENTS


//UTILS
double	ft_atodbl(const char *str);
char	**load_args_table(int num_args, char **argv);
void	ft_error(char *message);


#endif