#include "../inc/fractol.h"

void    calculate_mandelbrot(t_fractal *fractal)
{
    int i = 0;
    double x_tmp;

    fractal->flag = 1;
    fractal->z_x = 0.0;
    fractal->z_y = 0.0;
    // per cambiare zoom mi bastera' creare un hook che mi cambia il valore di zoom
    // e prende il valore di x e y del mouse
    fractal->c_x = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->c_y = (fractal->y / fractal->zoom) + fractal->offset_y;
    // calcolo la tendenza del punto a divergere
    while (++i < fractal->max_iter)
    {
        // parte reale
        x_tmp = fractal->z_x * fractal->z_x - fractal->z_y * fractal->z_y + fractal->c_x;
        // parte immaginaria
        fractal->z_y = 2.0 * fractal->z_x * fractal->z_y + fractal->c_y;
        fractal->z_x = x_tmp;
        // se tende all'infinito esco
        if ((fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) > __DBL_MAX__)
            break ;
    }
    // se non tendeva all'infinito sara' limityato e quindi avro' raggiunto il massimo numero di iterazioni
    // e lo coloro di nero
    if (i == fractal->max_iter)
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
    // altrimenti coloro il pixel in base al numero di iterazioni
    else
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}
void    *draw_mandelbrot(void *frac_void)
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
            calculate_mandelbrot(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
    // disegno l'immagine
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
    // printf("Mandelbrot Drawn.\n");
    // print_command_list();
    return (NULL);
}