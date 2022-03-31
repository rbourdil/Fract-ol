/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:56:07 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/31 18:16:14 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define LEFT_CLICK 1
#define RIGHT_CLICK 3

#define HUE_SHIFT 30
#define SAT_SHIFT 10
#define VAL_SHIFT 10

#define COLOR_1 1
#define COLOR_2 2

static void	zoom(int button, t_loc *loc, int x, int y)
{
	double	newrange;
	double	speed;

	if (button == SCROLL_UP)
		speed = 1 - SPEED;
	else
		speed = 1 + SPEED;
	newrange = loc->x_range * speed;
	loc->xb = ((double)x / WIDTH) * (loc->x_range - newrange) + loc->xb;
	loc->xe = newrange + loc->xb;
	loc->x_range = newrange;
	newrange = loc->y_range * speed;
	loc->yb = ((double)y / HEIGTH) * (loc->y_range - newrange) + loc->yb;
	loc->ye = newrange + loc->yb;
	loc->y_range = newrange;
}

static void	switch_color(int button, t_color *color, int hsv)
{
	if (button == SCROLL_UP)
	{
		if (hsv == HUE && color->hue + HUE_SHIFT <= 360)
			color->hue += HUE_SHIFT;
		else if (hsv == SAT && color->sat + SAT_SHIFT <= 100)
			color->sat += SAT_SHIFT;
		else if (hsv == VAL && color->val + VAL_SHIFT <= 100)
			color->val += VAL_SHIFT;
	}
	else
	{
		if (hsv == HUE && color->hue - HUE_SHIFT >= 0)
			color->hue -= HUE_SHIFT;
		else if (hsv == SAT && color->sat - SAT_SHIFT >= 0)
			color->sat -= SAT_SHIFT;
		else if (hsv == VAL && color->val - VAL_SHIFT >= 0)
			color->val -= VAL_SHIFT;
	}
}

static inline void	print_color_params(int mode, t_fractals fract)
{
	if (mode == COLOR_1)
		ft_printf("COLOR 1:\nH: %d ; S: %d ; V: %d\n", \
		fract.color1.hue, fract.color1.sat, fract.color1.val);
	else if (mode == COLOR_2)
		ft_printf("COLOR 2:\nH: %d ; S: %d ; V: %d\n", \
		fract.color2.hue, fract.color2.sat, fract.color2.val);
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
		else if (vars->mode == COLOR_1)
			switch_color(button, &vars->fract.color1, vars->hsv);
		else
			switch_color(button, &vars->fract.color2, vars->hsv);
		print_color_params(vars->mode, vars->fract);
	}
	else
		return (-1);
	mlx_destroy_image(vars->mlx, vars->data.img);
	new_image(vars);
	plot_fractal(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
