/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:31:57 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/22 15:31:59 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 640
# define MAX_ITER 50

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*ptr_pix;
	int		bit_per_pix;
	int		line_size;
	int		endian;
	int		x;
	int		y;
	int		choose;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	scale;
	double	offset_x;
	double	offset_y;
}	t_fractol;

void	init_fractol_params(t_fractol *fractol);
void	init_fractol_graphics(t_fractol *fractol);
void	draw(t_fractol *fractol);
void	color(t_fractol *fractol, int j);
void	print_usage(void);
void	check_args(int ac, char **av, t_fractol *fractol);
void	calculate(t_fractol *ptr);
void	julia(t_fractol *ptr);
void	mandelbrot(t_fractol *ptr);
void	quit_fractol(t_fractol *fractol, char *message);
int		key_press(int keycode, t_fractol *fractol);
int		mouse_press(int button, int x, int y, t_fractol *fractol);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		cross_press(t_fractol *fractol);
double	ft_atod(char *s);
int		ft_isnumeric_str(char *str);

#endif
