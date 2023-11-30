#include "../inc/fractol.h"

int    key_hook(int keycode, t_fractal *fractal)
{
    if (keycode == ESC)
    {
        // printf("ESC pressed!\n");
        killall_free(fractal);
    }
    else if (keycode == LEFT)
    {
        fractal->offset_x -= 42 / fractal->zoom;
        // printf("Shifted left!\n");
    }
    else if (keycode == RIGHT)
    {
        fractal->offset_x += 42 / fractal->zoom;
        // printf("Shifted right!\n");
    }
    else if (keycode == UP)
    {
        fractal->offset_y -= 42 / fractal->zoom;
        // printf("Shifted up!\n");
    }
    else if (keycode == DOWN)
    {
        fractal->offset_y += 42 / fractal->zoom;
        // printf("Shifted down!\n");
    }
    else if (keycode == PLUS)
    {
        fractal->zoom *= 1.1;
        // printf("Zoomed in!\n");
    }
    else if (keycode == MINUS)
    {
        fractal->zoom /= 1.1;
        // printf("Zoomed out!\n");
    }
    else if (keycode == SPACE)
    {
        fractal->max_iter += 10;
        // printf("Increased max iterations!\n");
    }
    else if (keycode == BACKSPACE)
    {
        fractal->max_iter -= 10;
        // printf("Decreased max iterations!\n");
    }
    else if (keycode == R)
    {
        fractal->color += fractal->color_shift_step;
        if (fractal->color > fractal->color_shift_max)
            fractal->color = fractal->color_shift_min;
        // printf("Increased color shift!\n");
    }
    else if (keycode == F)
    {
        fractal->color -= fractal->color_shift_step;
        if (fractal->color < fractal->color_shift_min)
            fractal->color = fractal->color_shift_max;
        // printf("Decreased color shift!\n");
    }
    else if (keycode == T)
    {
        fractal->color = 0;
        // printf("Reset color shift!\n");
    }
    else if (keycode == C)
    {
        fractal->color_shift_step += 1;
        // printf("Increased color shift step!\n");
    }
    else if (keycode == V)
    {
        fractal->color_shift_step -= 1;
        // printf("Decreased color shift step!\n");
    }
    else if (keycode == B)
    {
        fractal->color_shift_step = (255*255*255) / 100;
        // printf("Reset color shift step!\n");
    }
    else if (keycode == ONE)
    {
        fractal->color_shift_step = (255*255*255) / 100;
        fractal->color = 0xFCBE11;
        fractal->max_iter = 100;
        fractal->zoom = 300;
        fractal->offset_x = -2.1;
        fractal->offset_y = -1.21;
        // printf("Reset all!\n");
    }
    else {
        printf("Keycode: %d\n", keycode);
    }
    draw_fractal(fractal);
    return (0);
}
int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
    if (button == WHEEL_UP)
    {
        fractal->zoom *= 1.1f;
        fractal->offset_x -= ((WIDTH / 2) - x) / fractal->zoom;
        fractal->offset_y -= ((HEIGHT / 2) - y) / fractal->zoom;
        printf("Zoomed in!\n");
    }
    else if (button == WHEEL_DOWN)
    {
        fractal->zoom /= 1.1f;
        fractal->offset_x += (x - (WIDTH / 2)) / fractal->zoom;
        fractal->offset_y += (y - (HEIGHT / 2)) / fractal->zoom;
        printf("Zoomed out!\n");
    }
    draw_fractal(fractal);
    return (0);
}

// int mouse_hook_julia(int button, int x, int y, t_fractal *fractal)
// {
//     if (button == LEFT_CLICK)
//     {
//         fractal->c_x = (x / fractal->zoom) + fractal->offset_x;
//         fractal->c_y = (y / fractal->zoom) + fractal->offset_y;
//         printf("Julia set to: %f + %fi\n", fractal->c_x, fractal->c_y);
//     }
//     draw_fractal(fractal);
//     return (0);
// }