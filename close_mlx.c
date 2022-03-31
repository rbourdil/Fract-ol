/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:51:03 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/31 15:58:24 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

int	close_mlx(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
