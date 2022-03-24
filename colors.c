#include "img.h"

int	to_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	interpolate_color(t_color color1, t_color color2, double d)
{
	double	h;
	double	s;
	double	v;

	h = color1.hue + (color2.hue - color1.hue) * d;
	s = color1.sat + (color2.sat - color1.sat) * d;
	v = color1.val + (color2.val - color1.val) * d;
	return (hsv_to_rgb(h, s, v));
}
