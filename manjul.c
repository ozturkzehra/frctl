/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manjul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:08 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/17 18:58:56 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *ptr)
{
	ptr->y = 0;
	while (ptr->y < HEIGHT)
	{
		ptr->x = 0;
		while (ptr->x < WIDTH)
		{
			ptr->c_r = ((ptr->x - WIDTH / 2.0) / (WIDTH / 2.0)) * ptr->scale
				+ ptr->offset_x;
			ptr->c_i = ((ptr->y - HEIGHT / 2.0) / (HEIGHT / 2.0)) * ptr->scale
				+ ptr->offset_y;
			ptr->z_r = 0;
			ptr->z_i = 0;
			calculate(ptr);
			ptr->x++;
		}
		ptr->y++;
	}
}

void	julia(t_fractol *ptr)
{
	ptr->y = 0;
	while (ptr->y < HEIGHT)
	{
		ptr->x = 0;
		while (ptr->x < WIDTH)
		{
			ptr->z_r = ((ptr->x - WIDTH / 2.0) / (WIDTH / 2.0)) * ptr->scale
				+ ptr->offset_x;
			ptr->z_i = ((ptr->y - HEIGHT / 2.0) / (HEIGHT / 2.0)) * ptr->scale
				+ ptr->offset_y;
			calculate(ptr);
			ptr->x++;
		}
		ptr->y++;
	}
}
