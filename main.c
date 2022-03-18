#include "img.h"

int	main(int argc, char *argv[])
{
	t_vars		vars;

	if (argc < 2)
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, argv[1]);
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGTH);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits, &vars.data.len, &vars.data.endian);
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		vars.fract->choice = MANDELBROT;		
		vars.fract->f = &mandelbrot;
	}
	fract_params(&vars, vars.fract->choice, argv[2], argv[3]);
	(*vars.fract->f)(vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, move, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, zoom, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
