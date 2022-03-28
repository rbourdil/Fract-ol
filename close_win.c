/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:51:03 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 17:35:48 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

int	close_win(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
