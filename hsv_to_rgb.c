#include "img.h"

static int	rgb_red(double hue, double sat, double val)
{
	double	rgb;

	if (hue < 60.0 || hue >= 300.0)
		rgb = 255.0;
	else if (hue < 120.0)
		rgb = (((119.0 - hue) / 60.0) * sat + (1.0 - sat)) * 255.0;
	else if (hue < 240.0)
		rgb = (1.0 - sat) * 255.0;
	else
		rgb = (((hue - 240.0) / 60.0) * sat + (1.0 - sat)) * 255.0;
	return ((int)(rgb * val));
}

static int	rgb_green(double hue, double sat, double val)
{
	double	rgb;

	if (hue >= 240.0)
		rgb = (1.0 - sat) * 255.0;
	else if (hue >= 180.0)
		rgb = (((240.0 - hue) / 60.0) * sat + (1.0 - sat)) * 255.0;
	else if (hue >= 60.0)
		rgb = 255.0;
	else
		rgb = ((hue / 60.0) * sat + (1.0 - sat)) * 255.0;
	return ((int)(rgb * val));
}

static int	rgb_blue(double hue, double sat, double val)
{
	double	rgb;

	if (hue >= 300)
		rgb = (((360.0 - hue) / 60.0) * sat + (1.0 - sat)) * 255.0;
	else if (hue >= 240)
		rgb = 255.0;
	else if (hue >= 180)
		rgb = (((hue - 120.0) / 60.0) * sat + (1.0 - sat)) * 255.0;
	else
		rgb = (1.0 - sat) * 255.0;
	return ((int)(rgb * val));
}

int	hsv_to_rgb(double hue, double sat, double val)
{
	int	r;
	int	g;
	int	b;

	r = rgb_red(hue, sat, val);
	g = rgb_green(hue, sat, val);
	b = rgb_blue(hue, sat, val);
	return (to_color(0, r, g, b));
}
