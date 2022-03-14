#include "img.h"

int	render_next_frame(t_vars *vars)
{
	mandelbrot(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, &vars->data.len, &vars->data.endian);
	return (0);
}
