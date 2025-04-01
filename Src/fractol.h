/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 06:03:56 by alex              #+#    #+#             */
/*   Updated: 2025/04/01 19:37:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include "../include/libft/libft.h"
#include "../include/Minilibx/mlx.h"
#include "../include/Minilibx/mlx_int.h"

#define WIDTH 400
#define HEIGHT 400

#define MAND_MAX_X 2
#define MAND_MIN_X -2
#define MAND_MAX_Y 2
#define MAND_MIN_Y -2

#define GOLD 1
#define BLACK 0

///////////////////////////***Structs***///////////////////////////
typedef struct s_image_data t_image_data;
typedef struct s_complex_factors t_complex_factors;

typedef struct	s_image_data
{
	void	*img_var;
	char	*name;
	char	*bit_map_address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		(*set_def)(t_image_data *, t_complex_factors *);
	char	**config;
	int		max_iter;
	int		first_color;
	int		origin[2];
	double	zoom;
	double	with[2];
}				t_image_data;

typedef struct	s_mlx_enviroment
{
	void				*mlx_var;
	void				*window;
	t_image_data		*img_data;
}				t_mlx_enviroment;

typedef struct	s_complex_factors
{
	double		real;
	double		imaginary;
}	t_complex_factors;

//SET_MLX_ENVIROMENT_TO_RENDER
char	select_set_to_render(t_image_data *img, char **argv, int argz);
char	setup_mlx_enviroment(t_mlx_enviroment *mlx, t_image_data *img);
void	set_default_values(t_image_data *img);
void	create_hooks(t_mlx_enviroment *mlx);
void	destroy_mlx_componets(void (*f)(), void (*g)(), void (*t)(), t_mlx_enviroment *mlx);

//SETS
int		mandelbrot_set(t_image_data *img, t_complex_factors *z);
int		julia_set(t_image_data *img, t_complex_factors *z);
char	mand_jul_coords_necesary_conditions(double real, double imaginary);

//RENDER
void	render_set(t_mlx_enviroment *mlx, t_image_data *image);
void	scale_xy_to_image_coords(t_complex_factors *z, int x, int y, t_image_data *img);
void	apply_zoom_and_moves(t_complex_factors	*z, t_image_data *img);
void	buffering_pixel(int x, int y, t_image_data *img, int color);

//MANAGE COLOR
int		get_color_from_palethe(int i, int max_i);
int		select_color(int *color_map, int i, int max_i);

//MANAGE EVENTS
int		manage_key(int keysym, t_mlx_enviroment *mlx);
int		manage_mouse(int button, int x, int y, t_mlx_enviroment *mlx);
int		close_handler(t_mlx_enviroment *mlx);

//MATHS
size_t	ft_power_of(size_t  num, int power);
double	power_of(double  num, int power);

//UTILS
double	ft_atodbl(const char *str);
char	**load_args_table(int num_args, char **argv);
void	ft_error(char *message);


#endif