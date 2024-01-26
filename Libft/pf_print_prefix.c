/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:37:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 11:40:10 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	pf_print_prefix(t_print *tab)
{
	char	*prefix;

	prefix = pf_addprefix(tab);
	ft_putstr_fd(prefix, 1);
	free(prefix);
}
