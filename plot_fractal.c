#include "img.h"

void	plot_fractal(t_vars vars)
{
	double	n, ca, cb, color;
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			ca = ((double)x / WIDTH) * (vars.loc.xe - vars.loc.xb) + vars.loc.xb;
			cb = ((double)(HEIGTH - y) / HEIGTH) * (vars.loc.ye - vars.loc.yb) + vars.loc.yb;
			n = (*vars.fract.f)(ca, cb, vars.args);
			if (n > 0)
			{
				n = logbase(n, BOUND);
				color = interpolate_color(vars.fract.color1, vars.fract.color2, n);
				my_pixel_put(&vars.data, x, y, color); 
			}
			else
			{
				color = 0;
				my_pixel_put(&vars.data, x, y, 0);
			}
			y++;
		}
		x++;
	}
}
