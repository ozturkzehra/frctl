/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zehra <zehra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:31 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/18 02:49:08 by zehra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractol *fractol)
{
	if (!fractol)
		return (write(1, "Error: fractol pointer is null\n", 31),
			quit_fractol(fractol, ""), 1);
	if (keycode == 65307)
		quit_fractol(fractol, "");
	if (keycode == 65362)
		fractol->offset_y -= 0.1 * fractol->scale;
	if (keycode == 65364)
		fractol->offset_y += 0.1 * fractol->scale;
	if (keycode == 65361)
		fractol->offset_x -= 0.1 * fractol->scale;
	if (keycode == 65363)
		fractol->offset_x += 0.1 * fractol->scale;
	draw(fractol);
	return (0);
}

int	cross_press(t_fractol *fractol)
{
	quit_fractol(fractol, "");
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractol *fractol)
{
	x = y;
	y = x;
	if (button == 4)
		fractol->scale *= 0.9;
	if (button == 5)
		fractol->scale *= 1.1;
	draw(fractol);
	return (0);
}
