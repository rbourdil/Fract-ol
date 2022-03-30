/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:36:27 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/13 11:37:58 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long ptr, int *count)
{
	ft_putstr("0x", count);
	ft_puthex(ptr, "0123456789abcdef", count);
}
