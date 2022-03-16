#ifndef IMG_H
#define IMG_H

#include <mlx.h>
#include "/usr/include/X11/X.h"
#define XK_MISCELLANY
#include "/usr/include/X11/keysymdef.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGTH 800
#define BOUND 50
#define SPEED 0.1

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
	void	*mlx;
	void	*win;
	t_loc	loc;
	t_data	data;
}	t_vars;

void	my_pixel_put(t_data *data, int x, int y, int color);
int		square(int keycode, t_vars *vars);
int		to_color(int t, int r, int g, int b);
void	mandelbrot(t_vars vars);

int		move(int keycode, t_vars *vars);
int		zoom(int button, int x, int y, t_vars *vars);

void	add_cplx(t_cplx *cplx1, t_cplx cplx2);
void	mult_cplx(t_cplx *cplx1, t_cplx cplx2);
double	mod_cplx(t_cplx cplx1);

#endif
