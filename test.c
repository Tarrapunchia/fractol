#include "inc/fractol.h"
void    my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
    // prendo l'indirizzo di memoria del pixel che voglio disegnare
    char    *dst;

    // calcolo l'offset
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

    // scrivo i byte per disegnare il pixel
    *(unsigned int*)dst = color;
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
void    frac_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, 800, 800, "Hello world!");
    fractal->img = mlx_new_image(fractal->mlx, 800, 800);
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
    fractal->offset_x = -2.1;
    fractal->offset_y = -1.21;
    fractal->zy = 0;
    fractal->zx = 0;
    fractal->cy = 0;
    fractal->cx = 0;
    fractal->x = 0;
    fractal->y = 0;
    fractal->zoom = 300;
    fractal->max_iter = 100;
    fractal->color = 0xFCBE11;
}
void    calculate_mandelbrot(t_fractal *fractal)
{
    int i = 0;
    double x_tmp;

    fractal->zx = 0.0;
    fractal->zy = 0.0;
    // per cambiare zoom mi bastera' creare un hook che mi cambia il valore di zoom
    // e prende il valore di x e y del mouse
    fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
    // calcolo la tendenza del punto a divergere
    while (++i < fractal->max_iter)
    {
        // parte reale
        x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
        // parte immaginaria
        fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
        fractal->zx = x_tmp;
        // se tende all'infinito esco
        if ((fractal->zx * fractal->zx + fractal->zy * fractal->zy) > __DBL_MAX__)
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
    return (NULL);
}
int main(int argc, char **argv)
{
    t_fractal   *fractal;
    fractal = malloc(sizeof(t_fractal));
    if (!fractal)
        return (1);
    if (!ft_strncmp(argv[1], "--mandelbrot\0", 13) || !ft_strncmp(argv[1], "-m\0", 3))
    {
        frac_init(fractal);
        draw_mandelbrot(fractal);
        mlx_loop(fractal->mlx);
    }
    else if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
    {
        printf("Usage: ./fractol --mandelbrot (-m)\n");
        printf("                 --julia (-j)\n");
        printf("                 --burning-ship (-bs)\n");
        printf("                 --help (-h)\n");
    }
    else
    {
        printf("Error: invalid argument!\n");
        printf("Usage: ./fractol --mandelbrot (-m)\n");
        printf("                 --julia (-j)\n");
        printf("                 --burning-ship (-bs)\n");
        printf("                 --help (-h)\n");
        return (1);
    }
    return (0);
}
