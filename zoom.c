#include "img.h"

#define SCROLL_UP 4
#define SCROLL_DOWN 5

#define SPEED 0.01

static void	zoom_in(t_loc *loc, int x, int y)
{
	double	size;
	double	new_size;

	size = loc->xe - loc->xb;
	new_size = size * (1 - SPEED);
	loc->xb = ((double)x / WIDTH) * (size - new_size) + loc->xb;
	loc->xe -= new_size + loc->xb;
	size = loc->ye - loc->yb;
	new_size = size * (1 - SPEED);
	loc->yb = ((double)y / HEIGTH) * (size - new_size) + loc->yb;
	loc->ye = new_size + loc->yb;
}

static void	zoom_out(t_loc *loc, int x, int y)
{
	double	size;
	double	new_size;

	size = loc->xe - loc->xb;
	new_size = size * (1 + SPEED);
	loc->xb = ((double)x / WIDTH) * (size - new_size) + loc->xb;
	loc->xe -= new_size + loc->xb;
	size = loc->ye - loc->yb;
	new_size = size * (1 + SPEED);
	loc->yb = ((double)y / HEIGTH) * (size - new_size) + loc->yb;
	loc->ye = new_size + loc->yb;
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		zoom_in(&vars->loc, x, y);
	else if (button == SCROLL_DOWN)
		zoom_out(&vars->loc, x, y);
	return (0);
}
