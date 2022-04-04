/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:47:20 by rbourdil          #+#    #+#             */
/*   Updated: 2022/04/04 10:02:33 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	start_mlx(t_vars *vars, char *title)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, title);
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
}

void	new_image(t_vars *vars)
{
	vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	if (vars->data.img == NULL)
		close_mlx(vars);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, \
	&vars->data.len, &vars->data.endian);
}
