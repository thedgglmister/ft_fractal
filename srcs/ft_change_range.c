/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:40:32 by biremong          #+#    #+#             */
/*   Updated: 2017/03/07 23:40:35 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_range(t_params *params, int x, int y, double scale)
{
	double	center_x;
	double	center_y;

	center_x = DILATE(x, params->x_min, params->x_max, 0, WIN_SIZE - 1);
	center_y = DILATE(-y, params->y_min, params->y_max, -(WIN_SIZE - 1), 0);
	params->x_min = center_x - (center_x - params->x_min) * scale;
	params->x_max = center_x - (center_x - params->x_max) * scale;
	params->y_min = center_y - (center_y - params->y_min) * scale;
	params->y_max = center_y - (center_y - params->y_max) * scale;
}

void	ft_shift_range(t_params *params, int vert, int horz)
{
	double	width;
	double	shift;

	width = params->x_max - params->x_min;
	shift = SHIFT_PERCENT * width;
	params->x_min += shift * horz;
	params->x_max += shift * horz;
	params->y_min += shift * vert;
	params->y_max += shift * vert;
}
