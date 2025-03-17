
#ifndef FRACTOL_H
# define FRACTOL_H
#define WIDTH 800
#define HEIGHT 640
#define MAX_ITER 50

#include <stdlib.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

typedef struct s_fractol
{
	void    *mlx;
	void    *window;
	void    *image;
	void    *ptr_pix;
	int bit_per_pix;
	int line_size;
	int endian;
	int x;//piexl konumum 
	int y;//pixel konumum
	int choose; //man mı lu mu secmek için
	double  z_r;
	double  z_i;
	double  c_r;
	double  c_i;
	double scale;
	double offset_x;
	double offset_y;
}t_fractol;



void    init_fractol_params(t_fractol *fractol);
void    init_fractol_graphics(t_fractol *fractol);
void    draw(t_fractol *fractol);
void    color(t_fractol *fractol, int j);
void    print_usage(void);
void    check_args(int ac, char **av, t_fractol *fractol);
void    calculate(t_fractol *ptr);
void    julia(t_fractol *ptr);
void    mandelbrot(t_fractol *ptr);
void    quit_fractol(t_fractol *fractol, char *message);
int key_press(int keycode, t_fractol *fractol);
int mouse_press(int button, int x, int y, t_fractol *fractol);
int ft_strcmp(char *s1, char *s2);
int ft_strlen(char *str);
double	ft_atod(char *s);
void	*ft_memset(void *b, int c, size_t len);

#endif