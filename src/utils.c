#include "../inc/fractol.h"

void    frac_init(t_fractal *fractal, char *title, int flag)
{
    fractal->flag = flag;
    fractal->mlx = mlx_init();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, title);
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
    fractal->offset_x = -2.1;
    fractal->offset_y = -1.21;
    fractal->z_y = 0;
    fractal->z_x = 0;
    fractal->c_y = 0;
    fractal->c_x = 0;
    fractal->x = 0;
    fractal->y = 0;
    fractal->zoom = 300;
    fractal->max_iter = 100;
    fractal->color = BASE_COLOR;
    fractal->color_shift_step = (255*255*255) / 100;
    fractal->color_shift_max = 0xFFFFFF;
    fractal->color_shift_min = 0x000000;
    printf("Fractal Initialized.\n");
}
int	killall_free(t_fractal *fractal)
{
    printf("ESC pressed!\n");
    printf("Killing all processes...\n");
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	free(fractal);
    printf("Memory Cleared.\nExiting...\n");
    exit(1);
	return (0);
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

int check_valid(char *arg)
{
    if (!ft_strncmp(arg, "--mandelbrot\0", 13) || !ft_strncmp(arg, "-m\0", 3))
        return (1);
    else if (!ft_strncmp(arg, "--julia\0", 8) || !ft_strncmp(arg, "-j\0", 3))
        return (2);
    else if (!ft_strncmp(arg, "--burning-ship\0", 15) || !ft_strncmp(arg, "-bs\0", 4))
        return (3);
    else
        return (0);
}

int    check_args(int argc, char **argv)
{
    int valid;
    if (argc < 2)
    {
        printf("Error: missing argument!\n");
        printf("%s", INSTRUCTIONS);
        exit(1);
    }
    if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
    {
        printf("%s", INSTRUCTIONS);
        exit(1);
    }
    valid = check_valid(argv[1]);
    if (valid == 0)
    {
        printf("Error: invalid argument!\n");
        printf("%s", INSTRUCTIONS);
        exit(1);
    }
    return (valid);
}
float ft_strtof(const char *str)
{
    float result = 0.0f;
    int sign = 1;
    int decimal = 0;
    float decimalMultiplier = 0.1f;

    if (*str == '-')
    {
        sign = -1;
        str++;
    } 
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
        result = result * 10.0f + (*(str++) - '0');
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9') {
            result = result + (*(str++) - '0') * decimalMultiplier;
            decimalMultiplier *= 0.1f;
            decimal = 1;
        }
        return (result * sign);
    }
    return (sign * (float)sign * (float)((int)result));
}
