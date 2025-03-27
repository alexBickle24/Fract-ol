/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:56:59 by alex              #+#    #+#             */
/*   Updated: 2025/03/27 01:27:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argz, char **argv)
{
	t_mlx_enviroment		*mlx;
	t_image_data	*image;
	
	//parseo de limitees
	if (argz < 2)
		ft_error("Need more arguments\n");
	//seleccionar imagen segun argumentos;
	select_image_to_render(image, argv, argz);
	//conectar con API, crear ventana y crear objeto imagen.
	if ((mlx = setup_mlx_enviroment(&image)) == NULL)
		return (1);
	//renderizar el set que queramos representar
	render_set(mlx, image, mandelbrot_set);
	//mantener el programa en ejecucion hasta que evento (API X11) lo pare.
	mlx_loop(mlx->mlx_var);
	return (0);
}

t_mlx_enviroment	*setup_mlx_enviroment(t_image_data **image)
{
	t_mlx_enviroment		*mlx;

	mlx->mlx_var = mlx_init();
	if (!mlx->mlx_var)
		return (NULL);
	mlx->windows = mlx_new_window(mlx->mlx_var, mlx->win_data->height, mlx->win_data->height, "Fractol");
	if (!mlx->windows)
	{
		//free_window 
		return (NULL);
	}
	image[0]->img = mlx_new_image(mlx->mlx_var, HEIGHT, WIDTH);
	if (!image[0]->img)
	{
		//free_image and window
		return (NULL);
	}
	mlx->img_data->bit_map_address = mlx_get_data_addr(image[0]->img, &mlx->img_data->bits_per_pixel, &mlx->img_data->line_length, &mlx->img_data->endian);
	if (!mlx->img_data->bit_map_address)
	{
		//freee image and window
		return (NULL);
	}
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

void	mandelbrot_set(t_mlx_utils *mlx, t_image_data *img)
{
	
}

void	julia_set(t_mlx_utils *mlx, t_image_data *img)
{
	
}

char	**load_args_table(int num_args, char **argv)
{
	char	**table_args;
	int		i;
	
	if (num_args == 0)
		return (NULL);
	table_args = (char **)malloc(sizeof(char *) * num_args);
	if (!table_args)
		return (NULL);
	i = 1;
	while (i < (num_args - 1) || argv[i] != NULL)
	{
		table_args[i] = argv[i];
		i++;
	}
	return (table_args);
}

void	render_set(t_mlx_utils *mlx, t_image_data *image, int (*set_pixel)(t_mlx_utils *, t_image_data*, int, int))
{
	t_complex_factors	*z;
	int					pixel_color;
	int 				x;
	int 				y;

	x = -1 ;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			scale_xy_to_image_coords(&z, x, y);
			apply_zoom_and_moves(z, x, y);
			pixel_color = set_pixel(mlx, image, z->a, z->b);
			buffer_my_pixel(z->a, z->b, image->bit_map_address, pixel_color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_data, mlx->windows, image, x, y);//cambiar mlx_data por mlx enviroment.
}

void	xy_to_image_coords(t_complex_factors *z, int x, int y)
{
	double	origin_x;
	double	origin_y;
	
	origin_x = (WIDTH / 2);
	origin_y = (HEIGHT / 2);
	//los mivimeintos sobre la pantalla los voy a tener que meter antes de aplicar el algoritmo y el escalado
	z->a = (x - origin_x) * ((MAND_MAX_X - MAND_MIN_X) / (WIDTH - 0));
	z->b = (y - origin_y) * ((MAND_MAX_Y - MAND_MIN_Y) / (HEIGHT - 0));
	//o los meto despues del escalado conuna relacion
}

void		apply_zoom_and_moves(t_complex_factors	*z, int	x, int y)
{
	
}

//void mlx_put_image_to_window(mlx->mlx_data, mlx->windows, image, x, y);//cambiar mlx_data por mlx enviroment.

void	ft_error(char *message)
{
	if (!message)
		return ;
	ft_putstr_fd(message, 2);
	return (1);	
}

