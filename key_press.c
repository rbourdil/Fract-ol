/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:54:09 by rbourdil          #+#    #+#             */
/*   Updated: 2022/04/04 10:06:20 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

#define UP 0xFF52
#define DOWN 0xFF54
#define RIGHT 0xFF53
#define LEFT 0xFF51

#define Z 122
#define H 104
#define S 115
#define V 118
#define ESCAPE 0xff1b

static void	move(int key, t_loc *loc)
{	
	if (key == UP && loc->ye + (SPEED * loc->y_range) < D_MAX)
	{
		loc->yb += (SPEED * loc->y_range);
		loc->ye += (SPEED * loc->y_range);
	}
	else if (key == DOWN && loc->yb - (SPEED * loc->y_range) > (D_MAX * -1.0))
	{
		loc->yb -= (SPEED * loc->y_range);
		loc->ye -= (SPEED * loc->y_range);
	}
	else if (key == LEFT && loc->xb - (SPEED * loc->x_range) > (D_MAX * -1.0))
	{
		loc->xb -= (SPEED * loc->x_range);
		loc->xe -= (SPEED * loc->x_range);
	}
	else if (key == RIGHT && loc->xe + (SPEED * loc->x_range) < D_MAX)
	{
		loc->xb += (SPEED * loc->x_range);
		loc->xe += (SPEED * loc->x_range);
	}
	loc->x_range = loc->xe - loc->xb;
	loc->y_range = loc->ye - loc->yb;
}

int	key_press(int key, t_vars *vars)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		move(key, &vars->loc);
		mlx_destroy_image(vars->mlx, vars->data.img);
		new_image(vars);
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
	else if (key == ESCAPE)
		close_mlx(vars);
	return (0);
}
