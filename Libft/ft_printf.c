/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:36:25 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/23 09:41:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_print	*ft_initialize_tab(t_print *tab)
{
	tab->txt = 0;
	tab->col = 0;
	tab->sp = 0;
	tab->wdt = 0;
	tab->tl = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	t_print	*tab;

	if (format == NULL)
		return (-1);
	tab = (t_print *)malloc(sizeof(t_print));
	if (tab == NULL)
		return (-1);
	ft_initialize_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}
