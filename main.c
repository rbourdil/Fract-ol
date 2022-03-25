#include "img.h"

int	main(int argc, char *argv[])
{
	t_vars		vars;

	check_args(argc, argv);
	select_fract(&vars, argv);
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
