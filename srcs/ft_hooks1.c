/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:50:21 by biremong          #+#    #+#             */
/*   Updated: 2017/03/20 14:15:03 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_on_loop(void *param)
{
	t_params	*params;
	int			redraw;

	params = (t_params*)param;
	redraw = 0;
	if (params->zoom_in && (redraw = 1))
		ft_zoom_range(params, params->x_pos, params->y_pos, ZOOM_IN);
	if (params->zoom_out && (redraw = 1))
		ft_zoom_range(params, params->x_pos, params->y_pos, ZOOM_OUT);
	if ((params->up || params->down || params->right || params->left)
			&& (redraw = 1))
		ft_shift_range(params, params->up + params->down,
			params->right + params->left);
	if (params->pulse && (redraw = 1))
		params->pulse_i += PULSE_INCREMENT;
	if (redraw)
		ft_start_draw(params);
	return (0);
}

int		ft_on_mousemove(int x, int y, void *param)
{
	t_params *params;

	params = (t_params*)param;
	params->x_pos = x;
	params->y_pos = y;
	if (ft_strequ(params->fractal, "julia"))
	{
		ft_on_loop(params);
		ft_start_draw(params);
	}
	return (0);
}

int		ft_on_mousepress(int button, int x, int y, void *param)
{
	t_params *params;

	params = (t_params*)param;
	if (button == 5)
		ft_zoom_range(params, x, y, ZOOM_IN);
	else if (button == 4)
		ft_zoom_range(params, x, y, ZOOM_OUT);
	if (button == 5 || button == 4)
	{
		ft_shift_range(params, params->up + params->down,
				params->right + params->left);
		ft_start_draw(params);
	}
	return (0);
}

int		ft_on_exit(void *param)
{
	t_params	*params;
	int			i;

	params = (t_params*)param;
	params->kill_threads = 1;
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(params->threads[i], NULL);
	mlx_destroy_image(params->mlx, params->img);
	exit(0);
}
