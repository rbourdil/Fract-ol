#include "img.h"

void	print_help(void)
{
	printf("FRACTOL\n\n");
	printf("NAME\n\tfractol - displays the chosen fractal\n\n");
	printf("SYNOPSIS\n\t./fractol <fractal_name> [float] [float]\n\n");
	printf("ARGV[1]\n\tmandelbrot - displays the mandelbrot fractal\n\
	julia - displays the julia fractal\n\
	ship - displays the burning ship fractal\n\n");
	printf("ARGV[2]\n\tFor the julia fractal only: the real part of the\
 complex number argument\n\n");
	printf("ARGV[3]\n\tFor the julia fractal only: the imaginary part of the\
 complex number argument\n\n");
	printf("COMMANDS\n\troll the mouse wheel to modify parameters\n\
	Z - zoom mode\n\tH - hue mode\n\tS - saturation mode\n\tV - value mode\n\
	right click - switch to color 1\n\
	left_click - switch to color 2\n\n");
	exit(EXIT_SUCCESS);
}

void	check_args(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: %s <fractal_name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (!ft_strcmp(argv[1], "help"))
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc != 4 || !ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
		{
			printf("usage: %s <julia> <float> <float>\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
}
