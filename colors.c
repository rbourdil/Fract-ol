int	to_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	interpolate_color(int color1, int color2, double d)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = (double)get_t(color1) + ((double)(get_t(color2) - get_t(color1))) * d;
	r = (double)get_r(color1) + ((double)(get_r(color2) - get_r(color1))) * d;
	g = (double)get_g(color1) + ((double)(get_g(color2) - get_g(color1))) * d;
	b = (double)get_b(color1) + ((double)(get_b(color2) - get_b(color1))) * d;
	return (to_color((int)t, (int)r, (int)g, (int)b));
}
