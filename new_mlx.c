/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:47:20 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/31 16:15:10 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	start_mlx(t_vars *vars, char *title)
{
	if ((vars->mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	if ((vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, title)) == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
}

void	new_image(t_vars *vars)
{
	if ((vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH)) == NULL)
		close_mlx(vars);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits, \
	&vars->data.len, &vars->data.endian);
}
