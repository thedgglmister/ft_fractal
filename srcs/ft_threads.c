/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:45:38 by biremong          #+#    #+#             */
/*   Updated: 2017/03/20 14:13:14 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_create_threads(t_params *params)
{
	int	i;

	i = -1;
	while (++i < THREAD_COUNT)
		pthread_create(&params->threads[i], NULL, ft_draw_fractol, params);
}

void	ft_start_draw(t_params *params)
{
	ft_draw_fractol(NULL);
	mlx_clear_window(params->mlx, params->win);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
}

void	*ft_draw_fractol(void *param)
{
	static int	i = WIN_SIZE * WIN_SIZE;
	int			thread_i;
	int			x;
	int			y;
	t_params	*params;

	params = (t_params*)param;
	while (params && !params->kill_threads)
	{
		while (i < WIN_SIZE * WIN_SIZE && !params->kill_threads)
		{
			thread_i = i++;
			y = thread_i / WIN_SIZE;
			x = thread_i % WIN_SIZE;
			if (ft_strequ(params->fractal, "buddhabrot"))
				params->frac_func(params, x, y);
			else
				ft_draw_pix(params, x, y, params->frac_func(params, x, y));
		}
	}
	i = 0;
	while (i < WIN_SIZE * WIN_SIZE && !params)
		;
	return (NULL);
}
