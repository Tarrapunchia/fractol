#include "../inc/fractol.h"

void    draw_fractal(t_fractal *fractal)
{
    if (fractal->flag == 1)
        draw_mandelbrot(fractal);
    else if (fractal->flag == 2){
        printf("sono in julia_hook\n");
        draw_julia(fractal);
    }
}

void    random_double(t_fractal *fractal)
{
    fractal->c_x = (double)rand() / (double)RAND_MAX * 4 - 2;
    fractal->c_y = (double)rand() / (double)RAND_MAX * 4 - 2;
}