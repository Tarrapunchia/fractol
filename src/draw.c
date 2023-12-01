#include "../inc/fractol.h"

void    draw_fractal(t_fractal *fractal)
{
    if (fractal->flag == 1)
        draw_mandelbrot(fractal);
    else if (fractal->flag == 2)
        draw_julia(fractal);
    else if (fractal->flag == 3)
        draw_burningship(fractal);
    else if (fractal->flag == 4)
        draw_tricorn(fractal);
}
void    my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
    // prendo l'indirizzo di memoria del pixel che voglio disegnare
    char    *dst;

    // calcolo l'offset
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

    // scrivo i byte per disegnare il pixel
    *(unsigned int*)dst = color;
}
