/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:50:00 by rbourdil          #+#    #+#             */
/*   Updated: 2022/01/14 09:39:01 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define INT_MIN -2147483648

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putptr(unsigned long ptr, int *count);
void	ft_putnbr(int nbr, int *count);
void	ft_u_putnbr(unsigned int nbr, int *count);
void	ft_puthex(unsigned long nbr, const char base[15], int *count);
void	redirect(va_list *pap, char spec, int *count);

#endif
