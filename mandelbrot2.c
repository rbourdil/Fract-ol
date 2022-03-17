#include "img.h"

int	palette[3] = {0x00FF0000, 0x0000FF00, 0x000000FF};

int	mandelbrot_color(int x, int y, t_vars vars)
{
	int		n, color1, color2, color;
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
	mu = (double)n - mu;
	color1 = (int)mu % 3;
	color2 = (color1 + 1) % 3;
	color = interpolate_color(palette[color1], palette[color2], mu - (int)mu);
	return (color);
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
			my_pixel_put(&vars.data, x, y, n);
			y++;
		}
		x++;
	}
}
