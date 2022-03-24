#include "img.h"

static void	print_help(void)
{
	printf("FRACTOL\n\n");
	printf("NAME\n\tfractol - displays the chosen fractal\n\n");
	printf("SYNOPSIS\n\t./fractol <fractal_name> [a] [b]\n\n");
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

static void	init_fractal(t_vars *vars, char *argv[])
{	
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		vars->fract.choice = MANDELBROT;
		vars->fract.f = &mandelbrot;
	}
	else if (!ft_strcmp(argv[1], "julia"))
	{
		vars->fract.choice = JULIA;
		vars->fract.f = &julia;
	}
	else if (!ft_strcmp(argv[1], "ship"))
	{
		vars->fract.choice = BURNING_SHIP;
		vars->fract.f = &burning_ship;
	}
	else if (!ft_strcmp(argv[1], "help"))
		print_help();
	else
	{
		printf("usage: %s <fractal_name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}

static int	check_args(t_vars *vars, int argc, char *argv[])
{
	if (!ft_strcmp(argv[1], "help"))
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	else if (argc != 4 && vars->fract.choice == JULIA)
	{
		printf("usage: %s <julia> <a> <b>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars		vars;

	if (argc < 2)
	{
		printf("usage: %s <fractal_name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	init_fractal(&vars, argv);
	check_args(&vars, argc, argv);
	if (vars.fract.choice == JULIA)
		fract_params(&vars, argv[2], argv[3]);
	else
		fract_params(&vars, "none", "none");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, argv[1]);
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGTH);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits, &vars.data.len, &vars.data.endian);
	plot_fractal(vars);
	vars.mode = ZOOM;
	vars.hsv = HUE;
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_press, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, button_press, &vars);
	mlx_hook(vars.win, DestroyNotify, KeyReleaseMask, close, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
