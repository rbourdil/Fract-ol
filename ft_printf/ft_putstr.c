/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:34:34 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/14 13:27:55 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	if (str == NULL)
		ft_putstr("(null)", count);
	while (str && *str != '\0')
	{
		ft_putchar(*str, count);
		str++;
	}
}
