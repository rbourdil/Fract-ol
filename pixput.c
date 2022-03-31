/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:45:02 by rbourdil          #+#    #+#             */
/*   Updated: 2022/03/28 15:45:16 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

inline void	pixput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + x * (data->bits / 8) + y * data->len;
	*(unsigned int *)dst = color;
}
