/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:38:14 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/13 14:18:54 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', count);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	ft_putchar(nbr % 10 + '0', count);
}
