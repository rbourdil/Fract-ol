#include "img.h"

int	move(int keycode, t_vars *vars)
{
	double	size;

	size = vars->loc.ye - vars->loc.yb;
	if (keycode == XK_Up)
	{
		vars->loc.yb += SPEED * size;
		vars->loc.ye += SPEED * size;
	}
	else if (keycode == XK_Down)
	{
		vars->loc.yb -= SPEED * size;
		vars->loc.ye -= SPEED * size;
	}
	else if (keycode == XK_Left)
	{
		vars->loc.xb -= SPEED * size;
		vars->loc.xe -= SPEED * size;
	}
	else if (keycode == XK_Right)
	{
		vars->loc.xb += SPEED * size;
		vars->loc.xe += SPEED * size;
	}
	mlx_destroy_image(vars->mlx, vars->data.img);                               
	vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
 	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, &vars->data.len, &vars->data.endian);
	mandelbrot(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);            
	return (0);
}
