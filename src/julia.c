#include "../inc/fractol.h"

void    calculate_julia(t_fractal *fractal)
{
    int i = 0;
    double x_tmp;

    fractal->flag = 2;
    fractal->z_x = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->z_y = (fractal->y / fractal->zoom) + fractal->offset_y;
    while (++i < fractal->max_iter && (fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) < 4)
    {
        x_tmp = fractal->z_x;
        fractal->z_x =  fractal->z_x * fractal->z_x - fractal->z_y * fractal->z_y + fractal->c_x - 0.8;
        fractal->z_y = 2.0 * x_tmp * fractal->z_y + fractal->c_y;
        if ((fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) >= __DBL_MAX__)
            break ;
    }
    if (i == fractal->max_iter)
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
    else
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}
void    *draw_julia(t_fractal *fractal)
{
    fractal->x = 0;
    while (fractal->x < WIDTH)
    {
        fractal->y = 0;
        while (fractal->y < HEIGHT)
        {
            calculate_julia(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
    return (NULL);
}