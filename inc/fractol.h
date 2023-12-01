#ifndef FRACTOL_H
# define FRACTOL_H
/****************************************************************************/
/*                               LIBRARIES                                  */
/****************************************************************************/
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <time.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>
# include <complex.h>
# include "../libft/libft.h"
/****************************************************************************/
/*                               DEFINES                                    */
/****************************************************************************/
# define WIDTH 800
# define HEIGHT 800
# define INSTRUCTIONS "Usage: ./fractol --mandelbrot (-m)\n\
				 --julia (-j) (double) (double)\n\
				 --burning-ship (-bs)\n\
				 --help (-h)\n"
# define COMMANDS "Commands:\n\
				 Zoom: + -\n\
				 Move: arrows\n\
				 Change color: r f t\n\
				 Change color shift step: c v b\n\
				 Reset: 1\n\
				 Randomize Julia: j\n\
				 Exit: esc\n"

# define BASE_COLOR /* 0xFCBE11 */265
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLUS 61
# define MINUS 45
# define SPACE 32
# define BACKSPACE 65288
# define ENTER 65293
# define R 114
# define F 102
# define T 116
# define C 99
# define V 118
# define B 98
# define J 106
# define ONE 49
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 3

typedef struct s_fractal {
	int  flag;
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	double offset_x;
	double offset_y;
	int x;
	int y;
	double z_y;
	double z_x;
	double c_y;
	double c_x;
	double zoom;
	int max_iter;
	int color;
	int color_shift;
	int color_shift_max;
	int color_shift_min;
	int color_shift_step;
}   t_fractal;

/****************************************************************************/
/*                               PROTOTYPES                                 */
/****************************************************************************/
/* int	        create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb); */
// TO BE ADDED TO LIBFT
float ft_strtof(const char *str);
/****************************************************************************/
/*                               UTILS.C                                    */
/****************************************************************************/
void	frac_init(t_fractal *fractal, char* title, int flag);
int		killall_free(t_fractal *fractal);
int		check_valid(char *arg);
int		check_args(int argc, char **argv);
void	random_double(t_fractal *fractal);
// TO BE ADDED TO LIBFT
double	abs_double(double n);

/****************************************************************************/
/*                               HOOKS.C                                    */
/****************************************************************************/
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int button, int x, int y, t_fractal *fractal);

/****************************************************************************/
/*		                          DRAW.C                                    */
/****************************************************************************/
void	draw_fractal(t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);

/****************************************************************************/
/*                               MANDELBROT.C                               */
/****************************************************************************/
void	calculate_mandelbrot(t_fractal *fractal);
void	*draw_mandelbrot(void *frac_void);

/****************************************************************************/
/*                               JULIA.C                                    */
/****************************************************************************/
void	calculate_julia(t_fractal *fractal);
void	*draw_julia(t_fractal *fractal);

/****************************************************************************/
/*                               BURNINGSHIP.C                              */
/****************************************************************************/
void	calculate_burningship(t_fractal *fractal);
void	*draw_burningship(void *frac_void);

/****************************************************************************/
/*                               TRICORN.C                                  */
/****************************************************************************/
void	calculate_tricorn(t_fractal *fractal);
void	*draw_tricorn(void *frac_void);

#endif