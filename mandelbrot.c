/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:08 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 16:03:38 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

double	mandelbrot(double ca, double cb, t_args args)
{
	int		n;
	double	za;
	double	zb;
	double	tmp;
	double	p;

	(void)args;
	p = sqrt((ca - 1.0 / 4.0) * (ca - 1.0 / 4.0) + cb * cb);
	if (ca <= (p - 2.0 * p * p + 0.25))
		return (0.0);
	else if ((ca + 1.0) * (ca + 1.0) + cb * cb <= (1.0 / 16.0))
		return (0.0);
	za = 0.0;
	zb = 0.0;
	n = 0;
	while (n < BOUND && za * za + zb * zb < 4)
	{
		tmp = za;
		za = za * za - zb * zb + ca;
		zb = 2.0 * tmp * zb + cb;
		n++;
	}
	if (n == BOUND)
		return (0.0);
	return ((double)n + 1 - log(log2(sqrt(za * za + zb * zb))));
}
