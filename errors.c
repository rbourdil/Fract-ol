/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:51:26 by rbourdil          #+#    #+#             */
/*   Updated: 2022/04/04 10:07:51 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include <stdio.h>

void	print_help(void)
{
	ft_printf("FRACTOL\n\n");
	ft_printf("NAME\n\tfractol - displays the chosen fractal\n\n");
	ft_printf("SYNOPSIS\n\t./fractol <fractal_name> [float] [float]\n\n");
	ft_printf("ARGV[1]\n\tmandelbrot - displays the mandelbrot fractal\n\
	julia - displays the julia fractal\n\
	ship - displays the burning ship fractal\n\n");
	ft_printf("ARGV[2]\n\tFor the julia fractal only: the real part of the\
 complex number argument\n\n");
	ft_printf("ARGV[3]\n\tFor the julia fractal only: the imaginary part of\
 the complex number argument\n\n");
	ft_printf("COMMANDS\n\troll the mouse wheel to modify parameters\n\
	Z - zoom mode\n\tH - hue mode\n\tS - saturation mode\n\tV - value mode\n\
	right click - switch to color 1\n\
	left_click - switch to color 2\n\n");
	exit(EXIT_SUCCESS);
}

void	check_args(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("usage: %s <fractal_name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (!ft_strcmp(argv[1], "help"))
	{
		print_help();
		exit(EXIT_SUCCESS);
	}
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc != 4 || !ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
		{
			ft_printf("usage: %s <julia> <float> <float>\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
}

inline static int	check_lim(double val)
{
	if (val < -1.0 * D_MAX || val > D_MAX)
		return (0);
	if (val > -1.0 * D_MIN && val < D_MIN)
		return (0);
	return (1);
}

int	check_zoom(int button, t_loc loc, int x, int y)
{
	double	newrange;
	double	xb;
	double	xe;
	double	yb;
	double	ye;

	if (button == SCROLL_UP)
		newrange = loc.x_range * (1 - SPEED);
	else
		newrange = loc.x_range * (1 + SPEED);
	if (!check_lim(newrange))
		return (0);
	xb = ((double)x / WIDTH) * (loc.x_range - newrange) + loc.xb;
	xe = newrange + loc.xb;
	if (button == SCROLL_UP)
		newrange = loc.y_range * (1 - SPEED);
	else
		newrange = loc.y_range * (1 + SPEED);
	if (!check_lim(newrange))
		return (0);
	yb = ((double)y / HEIGTH) * (loc.y_range - newrange) + loc.yb;
	ye = newrange + loc.yb;
	if (!check_lim(xb) || !check_lim(xe) || !check_lim(yb) || !check_lim(ye))
		return (0);
	return (1);
}
