/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:27:06 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/14 09:36:00 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CONV 1
#define CHAR 0

int	ft_printf(const char *format, ...)
{
	int		state;
	int		count;
	va_list	ap;

	va_start(ap, format);
	state = CHAR;
	count = 0;
	while (*format != '\0')
	{
		if (state == CONV)
		{
			redirect(&ap, *format, &count);
			state = CHAR;
		}
		else if (*format != '%')
		{
			ft_putchar(*format, &count);
			state = CHAR;
		}
		else
			state = CONV;
		format++;
	}
	va_end(ap);
	return (count);
}
