#include "img.h"

#define SPEED 0.01

int	move(int keycode, t_vars *vars)
{
	if (keycode == XK_Up)
	{
		vars->loc.yb -= SPEED;
		vars->loc.ye -= SPEED;
	}
	else if (keycode == XK_Down)
	{
		vars->loc.yb += SPEED;
		vars->loc.ye += SPEED;
	}
	else if (keycode == XK_Left)
	{
		vars->loc.xb -= SPEED;
		vars->loc.xe -= SPEED;
	}
	else if (keycode == XK_Right)
	{
		vars->loc.xb += SPEED;
		vars->loc.xe += SPEED;
	}
	return (0);
}
