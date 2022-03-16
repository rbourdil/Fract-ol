#include "img.h"

#define SCROLL_UP 4
#define SCROLL_DOWN 5

#define SPEED 0.01

static void	zoom_in(t_loc *loc, int x, int y)
{
	double	size;
	double	newsize;

	size = loc->xe - loc->xb;
	newsize = size * (1 - SPEED);
	loc->xb = ((double)x / WIDTH) * (size - newsize) + loc->xb;
	loc->xe = newsize + loc->xb;
	size = loc->ye - loc->yb;
	newsize = size * (1 - SPEED);
	loc->yb = ((double)y / HEIGTH) * (size - newsize) + loc->yb;
	loc->ye = newsize + loc->yb;
}

static void	zoom_out(t_loc *loc, int x, int y)
{
	double	size;
	double	newsize;

	size = loc->xe - loc->xb;
	newsize = size * (1 + SPEED);
	loc->xb = ((double)x / WIDTH) * (size - newsize) + loc->xb;
	loc->xe = newsize + loc->xb;
	size = loc->ye - loc->yb;
	newsize = size * (1 + SPEED);
	loc->yb = ((double)y / HEIGTH) * (size - newsize) + loc->yb;
	loc->ye = newsize + loc->yb;
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		zoom_in(&vars->loc, x, HEIGTH - y);
	else if (button == SCROLL_DOWN)
		zoom_out(&vars->loc, x, HEIGTH - y);
	return (0);
}
