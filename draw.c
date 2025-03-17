/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:28 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/17 18:57:29 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->window);
	if (fractol->mlx == 0)
		exit(1);
	if (fractol->choose == 1)
		mandelbrot(fractol);
	if (fractol->choose == 2)
		julia(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0,
		0);
}

void	color(t_fractol *fractol, int color_value)
{
	char	*pixel;

	pixel = fractol->ptr_pix + (fractol->y * fractol->line_size + fractol->x
			* (fractol->bit_per_pix / 8));
	pixel[0] = (color_value >> 16) & 0xFF; // Kırmızı
	pixel[1] = (color_value >> 8) & 0xFF;  // Yeşil
	pixel[2] = color_value & 0xFF;         // Mavi
	pixel[3] = 0xFF;                       // Alpha (Tam opak)
}
