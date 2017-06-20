/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:58:40 by biremong          #+#    #+#             */
/*   Updated: 2017/03/20 13:09:37 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define WIN_SIZE 800
# define MAX_ITERATIONS 1200
# define ZOOM_IN 0.96
# define ZOOM_OUT (2 - ZOOM_IN)
# define SHIFT_PERCENT 0.02
# define PULSE_INCREMENT 0.002
# define THREAD_COUNT 32
# define DILATE(x,a,b,min,max) ((((b)-(a))*((x)-(min))/((max)-(min)))+(a))

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_str;
	char		*fractal;
	int			(*frac_func)();
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			zoom_in;
	int			zoom_out;
	int			up;
	int			down;
	int			right;
	int			left;
	int			pulse;
	double		pulse_i;
	int			x_pos;
	int			y_pos;
	pthread_t	threads[THREAD_COUNT];
	int			kill_threads;
}				t_params;

typedef struct	s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

/*
** main.c
*/
void			ft_init_params(t_params *params, int size, int ac, char *arg);
void			ft_handle_args(t_params *params, int argc, char *arg);
void			ft_set_hooks(t_params *params);
int				ft_strequ(char *s1, char *s2);

/*
** ft_hooks1.c
*/
int				ft_on_loop(void *param);
int				ft_on_mousepress(int button, int x, int y, void *param);
int				ft_on_mousemove(int x, int y, void *param);
int				ft_on_exit(void *param);

/*
** ft_hooks2.c
*/
int				ft_on_keypress(int keycode, void *param);
int				ft_buddha_keypress(int keycode, void *param);
int				ft_on_keyrelease(int keycode, void *param);

/*
** ft_threads.c
*/
void			ft_create_threads(t_params *params);
void			ft_start_draw(t_params *params);
void			*ft_draw_fractol(void *param);

/*
** ft_color.c
*/
int				ft_calc_color(int j, double r2, double i2, double pulse_i);
void			ft_draw_pix(t_params *params, int x, int y, int color);
void			ft_trace_point(t_params *params, t_cmplx c);
void			ft_brighten_pix(t_params *params, int x, int y);

/*
** ft_fractals.c
*/
int				ft_mandelbrot(t_params *params, int x, int y);
int				ft_julia(t_params *params, int x, int y);
int				ft_burning_ship(t_params *params, int x, int y);
int				ft_buddhabrot(t_params *params, int x, int y);
t_cmplx			ft_extra_smooth(char *name, t_cmplx z, t_cmplx c, t_cmplx z2);

/*
** ft_change_range.c
*/
void			ft_zoom_range(t_params *params, int x, int y, double scale);
void			ft_shift_range(t_params *params, int vert, int horz);

#endif
