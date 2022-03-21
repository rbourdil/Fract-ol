#include "img.h"

int	hsv_to_rgb(double hue, double sat, double val)
{
	double r = 0, g = 0, b = 0;

	if (sat == 0)
	{
		r = val;
		g = val;
		b = val;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (hue == 360)
			hue = 0;
		else
			hue = hue / 60;
		i = (int)hue;
		f = hue - i;

		p = val * (1.0 - sat);
		q = val * (1.0 - (sat * f));
		t = val * (1.0 - (sat * (1.0 - f)));

		switch (i)
		{
		case 0:
			r = val;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = val;
			b = p;
			break;

		case 2:
			r = p;
			g = val;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = val;
			break;

		case 4:
			r = t;
			g = p;
			b = val;
			break;

		default:
			r = val;
			g = p;
			b = q;
			break;
		}

	}
	return (to_color(0, (int)(r * 255.0), (int)(g * 255.0), (int)(b * 255.0)));
}
