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
        fractal->c_x = ft_strtof(argv[2]);
        fractal->c_y = ft_strtof(argv[3]);
    }
    draw_fractal(fractal);
    // if (flag == 1)
    // {
    //     frac_init(fractal, "Mandelbrot", flag);
    //     draw_mandelbrot(fractal);
    // }
    // else if (flag == 2)
    // {
    //     frac_init(fractal, "Julia", flag);
    //     fractal->c_x = ft_strtof(argv[2]);
    //     fractal->c_y = ft_strtof(argv[3]);
    //     draw_julia(fractal);
    // }
    mlx_key_hook(fractal->win, key_hook, fractal);
    mlx_mouse_hook(fractal->win, mouse_hook, fractal);
    mlx_loop(fractal->mlx);
    killall_free(fractal);
    return (0);
}
