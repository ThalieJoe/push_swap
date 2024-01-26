/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_checkcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:00 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/22 13:01:49 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_checkcase(t_print *tab, char c)
{
	if (c == 'c')
		pf_putchar(tab);
	if (c == 's')
		pf_putstr(tab, va_arg(tab->args, char *));
	if (c == 'p')
		pf_putptr(tab);
	if (c == 'd' || c == 'i')
		pf_putnbr(tab);
	if (c == 'u')
		pf_putu_base(tab, va_arg(tab->args, unsigned int), "0123456789");
	if (c == 'x')
		pf_putu_base(tab, va_arg(tab->args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		pf_putu_base(tab, va_arg(tab->args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		pf_putstr(tab, "%");
}
