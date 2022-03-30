/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:16:26 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/13 14:39:58 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	redirect(va_list *pap, char spec, int *count)
{
	if (spec == 'c')
		ft_putchar(va_arg(*pap, int), count);
	else if (spec == 's')
		ft_putstr(va_arg(*pap, char *), count);
	else if (spec == 'p')
		ft_putptr(va_arg(*pap, unsigned long), count);
	else if (spec == 'd')
		ft_putnbr(va_arg(*pap, int), count);
	else if (spec == 'i')
		ft_putnbr(va_arg(*pap, int), count);
	else if (spec == 'u')
		ft_u_putnbr(va_arg(*pap, unsigned int), count);
	else if (spec == 'x')
		ft_puthex(va_arg(*pap, unsigned int), "0123456789abcdef", count);
	else if (spec == 'X')
		ft_puthex(va_arg(*pap, unsigned int), "0123456789ABCDEF", count);
	else if (spec == '%')
		ft_putchar('%', count);
}
