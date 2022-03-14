#include "img.h"
#define ABS(x) ((x < 0) ? x * -1 : x)

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, "Moving Square");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGTH);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits, &vars.data.len, &vars.data.endian);
	vars.loc.xb = -2.0;
	vars.loc.xe = 0.47;
	vars.loc.yb = -1.12;
	vars.loc.ye = 1.12;
	mlx_hook(vars.win, KeyPress, KeyPressMask, move, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, zoom, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
