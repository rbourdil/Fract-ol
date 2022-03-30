/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:40:35 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/13 11:42:15 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nbr, const char base[15], int *count)
{
	if (nbr > 15)
		ft_puthex(nbr / 16, base, count);
	ft_putchar(base[nbr % 16], count);
}
