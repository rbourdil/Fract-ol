/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:52:25 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/30 14:36:55 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../ft_printf/ft_printf.h"

# define WIDTH 600
# define HEIGTH 600
# define KEY_PRESS_MASK 1L
# define KEY_RELEASE_MASK 2L
# define BUTTON_PRESS_MASK 4L
# define KEY_PRESS 2
# define BUTTON_PRESS 4
# define DESTROY_NOTIFY 17
# define BOUND 1000
# define SPEED 0.1
# define ZOOM 0
# define COLOR_1 1
# define COLOR_2 2
# define HUE 1
# define SAT 2
# define VAL 3
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

struct	s_fractals;

typedef struct s_cplx {
	double	a;
	double	b;
}	t_cplx;

typedef struct s_loc {
	double	xb;
	double	xe;
	double	yb;
	double	ye;
	double	x_range;
	double	y_range;
}	t_loc;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
}	t_data;

typedef struct s_args {
	double	ca;
	double	cb;
}	t_args;

typedef struct s_color {
	int	hue;
	int	sat;
	int	val;
}	t_color;

typedef struct s_fractals {
	int		choice;
	double	(*f)(double, double, t_args);
	t_color	color1;
	t_color	color2;
}	t_fractals;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_loc		loc;
	t_data		data;
	t_fractals	fract;
	t_args		args;
	int			mode;
	int			hsv;
}	t_vars;

void	plot_fractal(t_vars vars);
void	fract_params(t_vars *vars, char *arg1, char *arg2);
void	select_fract(t_vars *vars, char *argv[]);

double	mandelbrot(double ca, double cb, t_args args);
double	julia(double za, double zb, t_args args);
double	burning_ship(double za, double zb, t_args args);

int		key_press(int keycode, t_vars *vars);
int		button_press(int button, int x, int y, t_vars *vars);
int		close_win(t_vars *vars);

double	ft_atof(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(char c);
int		ft_isnum(char c);
int		ft_isfloat(char *s);

void	pixput(t_data *data, int x, int y, int color);
int		to_color(int t, int r, int g, int b);
int		smooth_color(t_color color1, t_color color2, double d);
int		hsv_to_rgb(double hue, double sat, double val);

void	print_help(void);
void	check_args(int argc, char *argv[]);
int		check_bounds(t_loc loc);

#endif
