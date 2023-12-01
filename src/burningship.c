#include "../inc/fractol.h"

void    calculate_burningship(t_fractal *fractal)
{
    int i = 0;
    double x_tmp;

    fractal->flag = 3;
    fractal->z_x = 0.0;
    fractal->z_y = 0.0;
    fractal->c_x = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->c_y = (fractal->y / fractal->zoom) + fractal->offset_y;
    while (++i < fractal->max_iter)
    {
        x_tmp = fractal->z_x * fractal->z_x - fractal->z_y * fractal->z_y + fractal->c_x;
        fractal->z_y = abs_double(2.0 * fractal->z_x * fractal->z_y) + fractal->c_y;
        fractal->z_x = x_tmp;
        if ((fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) > __DBL_MAX__)
            break ;
    }
    if (i == fractal->max_iter)
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
    else
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}
void    *draw_burningship(void *frac_void)
{
    t_fractal   *fractal;

    fractal = (t_fractal *)frac_void;
    fractal->x = 0;
    // coloro tutti i pixel dell'immagine
    // per cambiare il set di colori mi bastera' creare un hook che mi cambia il valore di fractal->color
    while (fractal->x < WIDTH)
    {
        fractal->y = 0;
        while (fractal->y < HEIGHT)
        {
            calculate_burningship(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
    // disegno l'immagine
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
    // printf("burning Drawn.\n");
    // print_command_list();
    return (NULL);
}