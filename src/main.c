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
    if (flag == 1)
    {
        frac_init(fractal, "Mandelbrot", flag);
        draw_mandelbrot(fractal);
    }
    else if (flag == 2)
    {
        printf("sono in julia\n");
        frac_init(fractal, "Julia", flag);
        draw_julia(fractal, ft_strtof(argv[2]), ft_strtof(argv[3]));
    }
    mlx_key_hook(fractal->win, key_hook, fractal);
    mlx_mouse_hook(fractal->win, mouse_hook, fractal);
    mlx_loop(fractal->mlx);
    killall_free(fractal);
    return (0);
}
