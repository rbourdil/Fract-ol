/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:32:01 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/13 14:38:49 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_putnbr(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_u_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0', count);
}
