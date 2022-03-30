/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:02:12 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 16:02:26 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
