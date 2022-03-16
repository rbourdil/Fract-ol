#include "img.h"

int	mandelbrot_color(int x, int y, t_vars vars)
{
	int		n;
	double	mu;
	t_cplx	c, z;

	c.a = ((double)x / WIDTH) * (vars.loc.xe - vars.loc.xb) + vars.loc.xb;
	c.b = ((double)y / HEIGTH) * (vars.loc.ye - vars.loc.yb) + vars.loc.yb;
	z.a = 0.0;
	z.b = 0.0;
	n = 0;
	while (n < BOUND && mod_cplx(z) < 2)
	{
		mult_cplx(&z, z);
		add_cplx(&z, c);
		n++;
	}
	mu = (double)n - (log(log(mod_cplx(z)))) / log(2.0);
	return ((int)mu);
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
