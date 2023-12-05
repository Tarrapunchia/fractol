/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:34 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/05 17:12:32 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_fractal(t_fractal *fractal)
{
	if (fractal->flag == 1)
		draw_mandelbrot(fractal);
	else if (fractal->flag == 2)
		draw_julia(fractal);
	else if (fractal->flag == 3)
		draw_burningship(fractal);
	else if (fractal->flag == 4)
		draw_tricorn(fractal);
}

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
