/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:12:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/23 09:54:20 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	pf_putchar(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->txt)
		pf_print_prefix(tab);
	tab->tl += write(1, &c, 1);
	if (tab->txt)
		ft_putstr_fd("\033[0m", 1);
	tab->txt = 0;
	tab->col = 0;
}
