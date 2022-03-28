/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:48:04 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 15:08:14 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static double	logbase(double n, double base)
{
	if (n > 0.0)
		return (log(n) / log(base));
	return (0.0);
}

void	plot_fractal(t_vars vars)
{
	double	n;
	double	ca;
	double	cb;
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			ca = ((double)x / WIDTH) * vars.loc.x_range + vars.loc.xb;
			cb = ((double)(HEIGTH - y) / HEIGTH) * \
			vars.loc.y_range + vars.loc.yb;
			n = logbase((*vars.fract.f)(ca, cb, vars.args), BOUND);
			if (n > 0.0)
				pixput(&vars.data, x, y, smooth_color(vars.fract.color1, \
				vars.fract.color2, n));
			else
				pixput(&vars.data, x, y, 0);
			y++;
		}
		x++;
	}
}
