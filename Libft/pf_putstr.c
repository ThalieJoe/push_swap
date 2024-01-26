/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 11:27:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_print(t_print *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		tab->tl += write(1, &str[i], 1);
		i++;
	}
}

void	pf_putstr(t_print *tab, char *str)
{
	if (str == NULL)
	{
		tab->tl += write(1, "(null)", 6);
		return ;
	}
	if (tab->txt)
		pf_print_prefix(tab);
	ft_print(tab, str);
	if (tab->txt)
		ft_putstr_fd("\033[0m", 1);
	tab->txt = 0;
	tab->col = 0;
}
