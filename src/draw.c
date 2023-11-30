#include "../inc/fractol.h"

void    draw_fractal(t_fractal *fractal)
{
    if (fractal->flag == 1)
        draw_mandelbrot(fractal);
    else if (fractal->flag == 2){
        printf("sono in julia_hook\n");
        draw_julia(fractal, fractal->c_x, fractal->c_y);
    }
}