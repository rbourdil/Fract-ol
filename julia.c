#include "img.h"

double	julia(double za, double zb, t_args args)
{
	int		n;
	double	ca;
	double	cb;
	double	tmp;

	ca = args.ca;
	cb = args.cb;
	n = 0;
	while (n < BOUND && za * za + zb * zb < 4)
	{
		tmp = za;
		za = za * za - zb * zb + ca;
		zb = 2.0 * tmp * zb + cb; 
		n++;
	}
	if (n == BOUND)
		return (0);
	return ((double)n + 1 - log(log2(sqrt(za * za + zb * zb))));
}
