/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:32:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 11:47:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	pf_putnbr(t_print *tab)
{
	long int	d;
	int			len;

	d = va_arg(tab->args, int);
	len = ft_nbrlen(d);
	if (tab->txt)
		pf_print_prefix(tab);
	ft_putnbr_fd(d, 1);
	tab->tl += len;
	if (tab->txt)
		ft_putstr_fd("\033[0m", 1);
	tab->txt = 0;
	tab->col = 0;
}
