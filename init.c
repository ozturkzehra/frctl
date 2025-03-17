/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:20 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/17 18:58:42 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol_graphics(t_fractol *fractol)
{
	if (fractol->mlx == NULL)
		fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		quit_fractol(fractol, "MiniLibX could not be initialized!!");
	if (fractol->window == NULL)
		fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT,
				"fract-ol");
	if (fractol->window == NULL)
		quit_fractol(fractol, "Window could not be created!");
	if (fractol->image == NULL)
		fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->image == NULL)
		quit_fractol(fractol, "Image could not be created!");
	fractol->ptr_pix = mlx_get_data_addr(fractol->image, &fractol->bit_per_pix,
			&fractol->line_size, &fractol->endian);
	if (fractol->ptr_pix == NULL)
		quit_fractol(fractol, "Image data address could not be retrieved!");
}

void	init_fractol_params(t_fractol *fractol)
{
	if (!fractol)
	{
		write(1, "Error: Invalid fractol pointer\n", 31);
		return ;
	}
	fractol->mlx = NULL;
	fractol->window = NULL;
	fractol->image = NULL;
	fractol->ptr_pix = NULL;
	fractol->bit_per_pix = 0;
	fractol->line_size = 0;
	fractol->endian = 0;
	fractol->x = 0;
	fractol->y = 0;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->scale = 2;
	fractol->z_r = 0.0;
	fractol->z_i = 0.0;
	fractol->c_r = -0.7;
	fractol->c_i = 0.27015;
}

void	quit_fractol(t_fractol *fractol, char *message)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (fractol->image)
		mlx_destroy_image(fractol->mlx, fractol->image);
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
	}
	free(fractol->mlx);
	fractol->mlx = NULL;
	fractol->ptr_pix = NULL;
	exit(1);
}
