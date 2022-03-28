/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:46:20 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 15:47:18 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

int	to_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

inline int	smooth_color(t_color color1, t_color color2, double d)
{
	double	h;
	double	s;
	double	v;

	h = (double)color1.hue + (double)(color2.hue - color1.hue) *d;
	s = (double)color1.sat + (double)(color2.sat - color1.sat) *d;
	v = (double)color1.val + (double)(color2.val - color1.val) *d;
	return (hsv_to_rgb(h, s / 100.0, v / 100.0));
}
