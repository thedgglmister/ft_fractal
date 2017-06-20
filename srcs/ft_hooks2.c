/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:44:38 by biremong          #+#    #+#             */
/*   Updated: 2017/03/08 14:14:05 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_on_keypress(int keycode, void *param)
{
	t_params *params;

	params = (t_params*)param;
	if (keycode == 6)
		params->zoom_in = 1;
	else if (keycode == 7)
		params->zoom_out = 1;
	else if (keycode == 53)
		ft_on_exit(params);
	else if (keycode == 257)
		params->zoom_in = !params->zoom_in;
	else if (keycode == 258)
		params->pulse = !params->pulse;
	else if (keycode == 126)
		params->up = 1;
	else if (keycode == 125)
		params->down = -1;
	else if (keycode == 123)
		params->left = -1;
	else if (keycode == 124)
		params->right = 1;
	else if (keycode == 49)
		params->pulse = 1;
	return (0);
}

int		ft_buddha_keypress(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_on_keyrelease(int keycode, void *param)
{
	t_params *params;

	params = (t_params*)param;
	if (keycode == 6)
		params->zoom_in = 0;
	else if (keycode == 7)
		params->zoom_out = 0;
	else if (keycode == 126)
		params->up = 0;
	else if (keycode == 125)
		params->down = 0;
	else if (keycode == 123)
		params->left = 0;
	else if (keycode == 124)
		params->right = 0;
	else if (keycode == 49)
		params->pulse = 0;
	return (0);
}
