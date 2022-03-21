#include "img.h"

void	fract_params(t_vars *vars)
{
	if (vars->fract->choice == MANDELBROT)
	{
		vars->loc.xb = -2.0;
		vars->loc.xe = 0.47;
		vars->loc.yb = -1.12;
		vars->loc.ye = 1.12;
	}
	vars->fract->color1 = 0;
	vars->fract->color2 = 360;
}
