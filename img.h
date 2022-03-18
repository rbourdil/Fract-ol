#ifndef IMG_H
#define IMG_H

#include <mlx.h>
#include "/usr/include/X11/X.h"
#define XK_MISCELLANY
#include "/usr/include/X11/keysymdef.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 600
#define HEIGTH 600
#define BOUND 1000
#define SPEED 0.1
#define	MANDELBROT 1
#define	JULIA 2

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
}	t_loc;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
}	t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_loc		loc;
	t_data		data;
	struct 		s_fractals	*fract;
}	t_vars;

typedef struct s_fractals {
	int		choice;
	void	(*f)(t_vars vars);
	int		color1;
	int		color2;
}	t_fractals;


void	mandelbrot(t_vars vars);
void	fract_params(t_vars *vars, int choice, char *color1, char *color2);

int		move(int keycode, t_vars *vars);
int		zoom(int button, int x, int y, t_vars *vars);

void	add_cplx(t_cplx *cplx1, t_cplx cplx2);
void	mult_cplx(t_cplx *cplx1, t_cplx cplx2);
double	mod_cplx(t_cplx cplx1);

double	logbase(double n, double base);

void	my_pixel_put(t_data *data, int x, int y, int color);

int		to_color(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		interpolate_color(int color1, int color2, double t);

int		ft_strcmp(char *s1, char *s2);

#endif
