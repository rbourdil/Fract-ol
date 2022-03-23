#include "img.h"

void	fract_params(t_vars *vars, char *arg1, char *arg2)
{
	if (vars->fract.choice == MANDELBROT)
	{
		vars->loc.xb = -2.0;
		vars->loc.xe = 0.47;
		vars->loc.yb = -1.12;
		vars->loc.ye = 1.12;
	}
	else if (vars->fract.choice == JULIA)
	{
		vars->loc.xb = -1.0;
		vars->loc.xe = 1.0;
		vars->loc.yb = -1.12;
		vars->loc.ye = 1.12;
		vars->args.ca = ft_atof(arg1);
		vars->args.cb = ft_atof(arg2);
	}
	vars->fract.color1.hue = 0.0;
	vars->fract.color1.sat = 1.0;
	vars->fract.color1.val = 0.0;
	vars->fract.color2.hue = 360.0;
	vars->fract.color2.sat = 0.0;
	vars->fract.color2.val = 1.0;
}
