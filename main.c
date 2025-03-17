/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:15 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/17 18:58:37 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	write(1, "Usage: ./fractol <fractal_type> [julia_x julia_y]\n", 51);
	write(1, "Available fractals:\n", 20);
	write(1, "  mandelbrot       - Mandelbrot set\n", 36);
	write(1, "  julia x y        - Julia set (complex number parameters)\n",
		59);
}

void	check_args(int ac, char **av, t_fractol *fractol)
{
	if (ac < 2)
		print_usage();
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		fractol->offset_x = -1.35;
		fractol->offset_y = -1;
		fractol->choose = 1;
		fractol->c_r = 0;
		fractol->c_i = 0;
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		fractol->choose = 2;
		if (ac == 4)
		{
			fractol->c_r = ft_atod(av[2]);
			fractol->c_i = ft_atod(av[3]);
		}
	}
	else
		(print_usage(), quit_fractol(fractol, ""));
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	init_fractol_params(&fractol);
	check_args(ac, av, &fractol);
	init_fractol_graphics(&fractol);
	draw(&fractol);
	mlx_key_hook(fractol.window, key_press, &fractol);
	mlx_mouse_hook(fractol.window, mouse_press, &fractol);
	mlx_loop(fractol.mlx);
	quit_fractol(&fractol, "done");
	return (0);
}
