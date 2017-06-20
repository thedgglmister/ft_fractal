/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:38:20 by biremong          #+#    #+#             */
/*   Updated: 2017/03/08 14:44:23 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_calc_color(int j, double r2, double i2, double pulse_i)
{
	double	grad;
	int		red;
	int		green;
	int		blue;

	if (j == MAX_ITERATIONS + 3)
		return (0);
	grad = (j + 1 - log2(log(sqrt(r2 + i2)))) / MAX_ITERATIONS;
	grad += pulse_i;
	red = 192 * fabs(sin(12.5 * M_PI * grad));
	green = 96 * fabs(sin(6 * M_PI * grad));
	blue = 192 * fabs(cos(8 * M_PI * grad - M_PI / 3));
	red <<= 16;
	green <<= 8;
	return (red | green | blue);
}

void	ft_trace_point(t_params *params, t_cmplx c)
{
	t_cmplx	z;
	double	temp;
	int		x;
	int		y;

	z.r = c.r;
	z.i = c.i;
	while (z.r >= params->x_min && z.r <= params->x_max \
			&& z.i >= params->y_min && z.i <= params->y_max)
	{
		x = DILATE(z.i, 0, WIN_SIZE - 1, params->x_min, params->x_max);
		y = DILATE(z.r, 0, WIN_SIZE - 1, params->y_min, params->y_max);
		ft_brighten_pix(params, x, y);
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = temp;
	}
}

void	ft_brighten_pix(t_params *params, int x, int y)
{
	int pix_index;

	pix_index = y * WIN_SIZE + x;
	((int*)(params->img_str))[pix_index] += 0x010101;
}

void	ft_draw_pix(t_params *params, int x, int y, int color)
{
	int pix_index;

	pix_index = y * WIN_SIZE + x;
	((int*)(params->img_str))[pix_index] = color;
}
