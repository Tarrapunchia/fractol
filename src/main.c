#include "../inc/fractol.h"

int main(int argc, char **argv)
{
    int flag;
    flag = check_args(argc, argv);
    t_fractal   *fractal;
    fractal = malloc(sizeof(t_fractal));
    if (!fractal)
        return (-1);
    printf("Fractal Allocated.\n");
    frac_init(fractal, "Fractol", flag);
    if (flag == 2)
    {
        if (argc == 5)
        {
            fractal->c_x = ft_strtof(argv[2]);
            fractal->c_y = ft_strtof(argv[3]);
        }
        else
            random_double(fractal);
    }
    draw_fractal(fractal);
    mlx_key_hook(fractal->win, key_hook, fractal);
    mlx_mouse_hook(fractal->win, mouse_hook, fractal);
    mlx_loop(fractal->mlx);
    killall_free(fractal);
    return (0);
}
