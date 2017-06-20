/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:40:21 by biremong          #+#    #+#             */
/*   Updated: 2017/06/20 15:08:37 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot(t_params *params, int x, int y)
{
	int		j;
	t_cmplx	c;
	t_cmplx	z;
	t_cmplx	z2;
	double	temp;
	int		limit;

	c.r = DILATE(x, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	c.i = DILATE(y, params->y_min, params->y_max, WIN_SIZE - 1, 0);
	z.r = c.r;
	z.i = c.i;
	limit =  pow(16, -(params->x_max - params->x_min - 2.21)) + 30;
	j = 0;
	while (j < limit)
	{
		if ((z2.r = z.r * z.r) +
				(z2.i = z.i * z.i) >= 4)
		{
			z2 = ft_extra_smooth(params->fractal, z, c, z2);
			return (ft_calc_color(j + 3, z2.r, z2.i, params->pulse_i));
		}
		temp = z2.r - z2.i + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = temp;
		j++;
	}
	return (0);
}

int		ft_julia(t_params *params, int x, int y)
{
	int		j;
	t_cmplx	c;
	t_cmplx	z;
	t_cmplx	z2;
	double	temp;
	int		limit;

	c.r = DILATE(params->x_pos, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	c.i = DILATE(params->y_pos, params->y_min, params->y_max, WIN_SIZE - 1, 0);
	z.r = DILATE(x, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	z.i = DILATE(y, params->y_min, params->y_max, WIN_SIZE - 1, 0);
	limit =  pow(16, -(params->x_max - params->x_min - 2.21)) + 30;
	j = 0;
	while (j < limit)
	{
		if ((z2.r = z.r * z.r) +
				(z2.i = z.i * z.i) >= 4)
		{
			z2 = ft_extra_smooth(params->fractal, z, c, z2);
			return (ft_calc_color(j + 3, z2.r, z2.i, params->pulse_i));
		}
		temp = z2.r - z2.i + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = temp;
		j++;
	}
	return (0);
}

int		ft_burning_ship(t_params *params, int x, int y)
{
	int		j;
	t_cmplx	c;
	t_cmplx	z;
	t_cmplx	z2;
	double	temp;
	int		limit;

	c.r = DILATE(x, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	c.i = DILATE(y, params->y_min, params->y_max, WIN_SIZE - 1, 0);
	z.r = c.r;
	z.i = c.i;
	limit =  pow(16, -(params->x_max - params->x_min - 2.21)) + 30;
	j = 0;
	while (j < limit)
	{
		if ((z2.r = z.r * z.r) +
				(z2.i = z.i * z.i) >= 4)
		{
			z2 = ft_extra_smooth(params->fractal, z, c, z2);
			return (ft_calc_color(j + 3, z2.r, z2.i, params->pulse_i));
		}
		temp = z2.r - z2.i - c.r;
		z.i = 2 * fabs(z.r * z.i) - c.i;
		z.r = temp;
		j++;
	}
	return (0);
}

int		ft_buddhabrot(t_params *params, int x, int y)
{
	int		j;
	t_cmplx	c;
	t_cmplx	z;
	t_cmplx	z2;
	double	temp;

	c.r = DILATE(x, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	c.i = DILATE(y, params->y_min, params->y_max, WIN_SIZE - 1, 0);
	z.r = c.r;
	z.i = c.i;
	j = 0;
	while (j < MAX_ITERATIONS)
	{
		if ((z2.r = z.r * z.r) +
				(z2.i = z.i * z.i) >= 4)
			ft_trace_point(params, c);
		temp = z2.r - z2.i + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = temp;
		j++;
	}
	return (0);
}

t_cmplx	ft_extra_smooth(char *name, t_cmplx z, t_cmplx c, t_cmplx z2)
{
	int		i;
	int		sign;
	double	temp;

	sign = (ft_strequ(name, "burning_ship") ? -1 : 1);
	i = 0;
	while (i++ < 3)
	{
		temp = z2.r - z2.i + c.r * sign;
		z.i = 2 * (sign == 1 ? z.r * z.i : fabs(z.r * z.i)) + c.i * sign;
		z.r = temp;
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
	}
	return (z2);
}
