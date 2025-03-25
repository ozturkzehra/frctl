/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:15 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/25 00:13:09 by fatmoztu         ###   ########.fr       */
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
	if (ac < 2 || ac > 4)
		(print_usage(), quit_fractol(fractol, ""));
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		if (ac > 2)
			(print_usage(), quit_fractol(fractol, ""));
		fractol->choose = 1;
		fractol->c_r = 0;
		fractol->c_i = 0;
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		fractol->choose = 2;
		if (ac == 4 && ac != 3)
		{
			if (!ft_isnumeric_str(av[2]) || !ft_isnumeric_str(av[3]))
				(print_usage(), quit_fractol(fractol, ""));
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
	mlx_hook(fractol.window, 17, 0, cross_press, &fractol);
	mlx_loop(fractol.mlx);
	quit_fractol(&fractol, "done");
	return (0);
}
