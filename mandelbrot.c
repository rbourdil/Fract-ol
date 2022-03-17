#include "img.h"

int	mandelbrot_color(int x, int y, t_vars vars)
{
	int		n;
	double	ca, cb, za, zb, dza, dzb, tmp, mod_z, mod_dz, ret;

	ca = ((double)x / WIDTH) * (vars.loc.xe - vars.loc.xb) + vars.loc.xb;
	cb = ((double)y / HEIGTH) * (vars.loc.ye - vars.loc.yb) + vars.loc.yb;
	za = 0.0;
	zb = 0.0;
	dza = 0.0;
	dzb = 0.0;
	n = 0;
	while (n < BOUND && za * za + zb * zb < 4)
	{
		tmp = za;
		za = za * za - zb * zb + ca;
		zb = 2 * tmp * zb + cb; 
		tmp = dza;
		dza = 2 * (za * dza - zb * dzb) + 1;
		dzb = 2 * (za * dzb + zb * tmp);
		n++;
	}
	mod_z = sqrt(za * za + zb * zb);
	mod_dz = sqrt(dza * dza + dzb * dzb);
	ret = mod_z * log(mod_z) / mod_dz;
	return ((int)ret);
}

void	mandelbrot(t_vars vars)
{
	int	n;
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			n = mandelbrot_color(x, HEIGTH - y, vars);
			my_pixel_put(&vars.data, x, y, n * n);
			y++;
		}
		x++;
	}
}
