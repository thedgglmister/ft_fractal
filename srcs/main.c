/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:29:12 by biremong          #+#    #+#             */
/*   Updated: 2017/03/20 14:14:14 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_params	params;

	ft_init_params(&params, sizeof(params), ac, av[1]);
	ft_set_hooks(&params);
	ft_create_threads(&params);
	ft_start_draw(&params);
	mlx_loop(params.mlx);
	return (0);
}

void	ft_init_params(t_params *params, int size, int ac, char *arg)
{
	int bpp;
	int ls;
	int end;
	int i;

	i = -1;
	while (++i < size)
		((char*)params)[i] = 0;
	ft_handle_args(params, ac, arg);
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIN_SIZE, WIN_SIZE, "WHAT");
	params->img = mlx_new_image(params->mlx, WIN_SIZE, WIN_SIZE);
	params->img_str = mlx_get_data_addr(params->img, &bpp, &ls, &end);
	params->x_min = -2;
	params->x_max = 2;
	params->y_min = -2;
	params->y_max = 2;
}

void	ft_handle_args(t_params *params, int ac, char *arg)
{
	if (ac != 2)
	{
		write(1, "usage: fractol [\"mandelbrot\" | \
\"julia\" | \"burning_ship\" | \"buddhabrot\"]\n", 72);
		exit(0);
	}
	else if (ft_strequ((params->fractal = arg), "mandelbrot"))
		params->frac_func = &ft_mandelbrot;
	else if (ft_strequ((params->fractal = arg), "julia"))
		params->frac_func = &ft_julia;
	else if (ft_strequ((params->fractal = arg), "burning_ship"))
		params->frac_func = &ft_burning_ship;
	else if (ft_strequ((params->fractal = arg), "buddhabrot"))
		params->frac_func = &ft_buddhabrot;
	else
	{
		write(1, "usage: fractol [\"mandelbrot\" | \
\"julia\" | \"burning_ship\" | \"buddhabrot\"]\n", 72);
		exit(0);
	}
}

void	ft_set_hooks(t_params *params)
{
	if (ft_strequ(params->fractal, "buddhabrot"))
	{
		mlx_hook(params->win, 2, 0, ft_buddha_keypress, NULL);
		return ;
	}
	mlx_hook(params->win, 2, 0, ft_on_keypress, params);
	mlx_hook(params->win, 3, 0, ft_on_keyrelease, params);
	mlx_hook(params->win, 4, 0, ft_on_mousepress, params);
	mlx_hook(params->win, 6, 0, ft_on_mousemove, params);
	mlx_loop_hook(params->mlx, ft_on_loop, params);
}

int		ft_strequ(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
