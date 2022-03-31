/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:51:26 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/31 18:00:25 by rbourdil         ###   ########.fr       */
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
