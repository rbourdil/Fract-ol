#include "img.h"

double	mandelbrot_color(double ca, double cb)
{
	int		n;
	double	za, zb, tmp;

	za = 0.0;
	zb = 0.0;
	n = 0;
	while (n < BOUND && za * za + zb * zb < 4)
	{
		tmp = za;
		za = za * za - zb * zb + ca;
		zb = 2 * tmp * zb + cb; 
		n++;
	}
	if (n == BOUND)
		return (0);
	return ((double)n + 1 - log(log2(sqrt(za * za + zb * zb))));
}

void	mandelbrot(t_vars vars)
{
	double	n, ca, cb, p;
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
			p = sqrt((ca - 1.0 / 4.0) * (ca - 1.0 / 4.0) + cb * cb);
			if (ca <= (p - 2.0 * p * p + 0.25))
				n = 0.0;
			else if ((ca + 1.0) * (ca + 1.0) + cb * cb <= (1.0 / 16.0))
				n = 0.0;	
			else
				n = mandelbrot_color(ca, cb);
			n = logbase(n, BOUND);
			my_pixel_put(&vars.data, x, y, interpolate_color((n > 0) ? vars.fract->color1 : 0, vars.fract->color2, n));
			y++;
		}
		x++;
	}
}
