#include "img.h"

#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define LEFT_CLICK 1
#define RIGHT_CLICK 3

static void	zoom(int button, t_loc *loc, int x, int y)
{
	double	size;
	double	newsize;
	double	speed;

	if (button == SCROLL_UP)
		speed = 1 - SPEED;
	else if (button == SCROLL_DOWN)
		speed = 1 + SPEED;
	size = loc->xe - loc->xb;
	newsize = size * speed;
	loc->xb = ((double)x / WIDTH) * (size - newsize) + loc->xb;
	loc->xe = newsize + loc->xb;
	size = loc->ye - loc->yb;
	newsize = size * speed;
	loc->yb = ((double)y / HEIGTH) * (size - newsize) + loc->yb;
	loc->ye = newsize + loc->yb;
}

static void	switch_color(int button, t_vars *vars)
{
	if (button == SCROLL_UP)
	{
		if (vars->mode == COLOR_1)
		{
			if (vars->hsv == HUE && (vars->fract.color1.hue + COLOR_SHIFT) <= 360)
				vars->fract.color1.hue += COLOR_SHIFT;
			else if (vars->hsv == SAT && (vars->fract.color1.sat + 0.1) <= 1.0)
				vars->fract.color1.sat += 0.1;
			else if (vars->hsv == VAL && (vars->fract.color1.val + 0.1) <= 1.0)
				vars->fract.color1.val += 0.1;
		}
		else if (vars->mode == COLOR_2)
		{
			if (vars->hsv == HUE && (vars->fract.color2.hue + COLOR_SHIFT) <= 360)
				vars->fract.color2.hue += COLOR_SHIFT;
			else if (vars->hsv == SAT && (vars->fract.color2.sat + 0.1) <= 1.0)
				vars->fract.color2.sat += 0.1;
			else if (vars->hsv == VAL && (vars->fract.color2.val + 0.1) <= 1.0)
				vars->fract.color2.val += 0.1;
		}
	}
	else
	{
		if (vars->mode == COLOR_1)
		{
			if (vars->hsv == HUE && (vars->fract.color1.hue - COLOR_SHIFT) >= 0)
				vars->fract.color1.hue -= COLOR_SHIFT;
			else if (vars->hsv == SAT && (vars->fract.color1.sat - 0.1) >= 0)
				vars->fract.color1.sat -= 0.1;
			else if (vars->hsv == VAL && (vars->fract.color1.val - 0.1) >= 0)
				vars->fract.color1.val -= 0.1;
		}
		else if (vars->mode == COLOR_2)
		{
			if (vars->hsv == HUE && (vars->fract.color2.hue - COLOR_SHIFT) >= 0)
				vars->fract.color2.hue -= COLOR_SHIFT;
			else if (vars->hsv == SAT && (vars->fract.color2.sat - 0.1) >= 0)
				vars->fract.color2.sat -= 0.1;
			else if (vars->hsv == VAL && (vars->fract.color2.val - 0.1) >= 0)
				vars->fract.color2.val -= 0.1;
		}
	}
}

int	button_press(int button, int x, int y, t_vars *vars)
{
	if (button == LEFT_CLICK)
		vars->mode = COLOR_1;
	else if (button == RIGHT_CLICK)
		vars->mode = COLOR_2;
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (vars->mode == ZOOM)
			zoom(button, &vars->loc, x, HEIGTH - y);
		else
			switch_color(button, vars);
	}
	else
		return (-1);
	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, &vars->data.len, &vars->data.endian);
	plot_fractal(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
