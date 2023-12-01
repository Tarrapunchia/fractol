#include "../inc/fractol.h"

void    calculate_julia(t_fractal *fractal)
{
    int i = 0;
    double x_tmp;

    fractal->flag = 2;
    fractal->z_x = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->z_y = (fractal->y / fractal->zoom) + fractal->offset_y;
    // per cambiare zoom mi bastera' creare un hook che mi cambia il valore di zoom
    // e prende il valore di x e y del mouse
    // calcolo la tendenza del punto a divergere
    while (++i < fractal->max_iter && (fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) < 4)
    {
        // parte reale
        x_tmp = fractal->z_x;
        fractal->z_x =  fractal->z_x * fractal->z_x - fractal->z_y * fractal->z_y + fractal->c_x - 0.8;
        // parte immaginaria
        fractal->z_y = 2.0 * x_tmp * fractal->z_y + fractal->c_y;
        // se tende all'infinito esco
        if ((fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) >= __DBL_MAX__)
            break ;
    }
    // se non tendeva all'infinito sara' limitato e quindi avro' raggiunto il massimo numero di iterazioni
    // e lo coloro di nero
    if (i == fractal->max_iter)
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
    // altrimenti coloro il pixel in base al numero di iterazioni
    else
        my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}
void    *draw_julia(t_fractal *fractal)
{
    fractal->x = 0;
    // coloro tutti i pixel dell'immagine
    // per cambiare il set di colori mi bastera' creare un hook che mi cambia il valore di fractal->color
    // mlx_mouse_get_pos(fractal->mlx, fractal->win, &fractal->x, &fractal->y);
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
    // disegno l'immagine
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
    // printf("julia Drawn.\n");
    // print_command_list();
    return (NULL);
}