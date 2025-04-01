/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 06:03:56 by alex              #+#    #+#             */
/*   Updated: 2025/03/31 09:26:30 by alex             ###   ########.fr       */
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
	void				*mlx_var;
	void				*window;
	t_image_data		*img_data;
}				t_mlx_enviroment;

typedef struct	s_image_data
{
	void	*img_var;
	char	*name;
	char	*bit_map_address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	(*set_def)(t_mlx_enviroment *, t_image_data *, t_complex_factors *);
	char	**config;
	int		max_iter;
	int		first_color;
	double	zoom;
	int		origin[2];
	double		with[2];
}				t_image_data;

typedef struct	s_complex_factors
{
	double		real;
	double		imaginary;
}	t_complex_factors;

//SET_MLX_ENVIROMENT_TO_RENDER
char	select_set_to_render(t_image_data *img, char **argv, int argz);
char	*setup_mlx_enviroment(t_mlx_enviroment *mlx, t_image_data *img);
void	set_default_values(t_image_data *img);

//SETS
void	mandelbrot_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z);
void	julia_set(t_mlx_enviroment *mlx, t_image_data *img, t_complex_factors *z);
char	mand_jul_coords_necesary_conditions(double real, double imaginary);

//RENDER
void	render_set(t_mlx_enviroment *mlx, t_image_data *image);
void	xy_to_image_coords(t_complex_factors *z, int x, int y, t_image_data *img);
void	apply_zoom_and_moves(t_complex_factors	*z, t_image_data *img);
void	buffer_my_pixel(int x, int y, t_image_data *img, int color);

//MATHS
size_t	ft_power_of(size_t  num, int power);

//MANAGE EVENTS



//UTILS
double	ft_atodbl(const char *str);
char	**load_args_table(int num_args, char **argv);
void	ft_error(char *message);


#endif