/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:50:19 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 13:50:40 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

inline static double	ft_abs(double n)
{
	if (n < 0.0)
		return (n * -1.0);
	return (n);
}

double	burning_ship(double ca, double cb, t_args args)
{
	int		n;
	double	za;
	double	zb;
	double	tmp;

	(void)args;
	za = 0.0;
	zb = 0.0;
	n = 0;
	while (n < BOUND && za * za + zb * zb < 10)
	{
		tmp = za;
		za = za * za - zb * zb + ca;
		zb = ft_abs(2.0 * tmp * zb) + cb;
		n++;
	}
	if (n == BOUND)
		return (0);
	return ((double)n + 1 - log(log2(sqrt(za * za + zb * zb))));
}
