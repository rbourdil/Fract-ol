#include "img.h"

#define SPEED 0.01

int	move(int keycode, t_vars *vars)
{
	double	size;

	size = vars->loc.ye - vars->loc.yb;
	if (keycode == XK_Up)
	{
		vars->loc.yb += SPEED * size;
		vars->loc.ye += SPEED * size;
	}
	else if (keycode == XK_Down)
	{
		vars->loc.yb -= SPEED * size;
		vars->loc.ye -= SPEED * size;
	}
	else if (keycode == XK_Left)
	{
		vars->loc.xb -= SPEED * size;
		vars->loc.xe -= SPEED * size;
	}
	else if (keycode == XK_Right)
	{
		vars->loc.xb += SPEED * size;
		vars->loc.xe += SPEED * size;
	}
	return (0);
}
