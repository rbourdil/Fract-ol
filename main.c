/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:08:44 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/31 16:00:39 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	start_mlx(&vars, argv[1]);
	new_image(&vars);
	plot_fractal(vars);
	vars.mode = ZOOM;
	vars.hsv = HUE;
	mlx_hook(vars.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &vars);
	mlx_hook(vars.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_press, &vars);
	mlx_hook(vars.win, DESTROY_NOTIFY, KEY_RELEASE_MASK, close_mlx, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
