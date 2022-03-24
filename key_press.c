#include "img.h"

#define UP 0xFF52
#define DOWN 0xFF54
#define RIGHT 0xFF53
#define LEFT 0xFF51

#define Z 122
#define H 104
#define S 115
#define V 118

static void	move(int key, t_vars *vars)
{	
	double	size;

	size = vars->loc.ye - vars->loc.yb;
	if (key == UP)
	{
		vars->loc.yb += SPEED * size;
		vars->loc.ye += SPEED * size;
	}
	else if (key == DOWN)
	{
		vars->loc.yb -= SPEED * size;
		vars->loc.ye -= SPEED * size;
	}
	else if (key == LEFT)
	{
		vars->loc.xb -= SPEED * size;
		vars->loc.xe -= SPEED * size;
	}
	else if (key == RIGHT)
	{
		vars->loc.xb += SPEED * size;
		vars->loc.xe += SPEED * size;
	}
}

int	key_press(int key, t_vars *vars)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		move(key, vars);
		mlx_destroy_image(vars->mlx, vars->data.img);                               
		vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
 		vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, &vars->data.len, &vars->data.endian);
		plot_fractal(*vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);            
	}
	else if (key == Z)
		vars->mode = ZOOM;
	else if (key == H)
		vars->hsv = HUE;
	else if (key == S)
		vars->hsv = SAT;
	else if (key == V)
		vars->hsv = VAL;
	return (0);
}
