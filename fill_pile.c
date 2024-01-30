/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:38:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_pile(long *numbers, int size)
{
	t_list	*pile;
	int		i;
	t_list	*node;

	pile = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(&numbers[i]);
		ft_lstadd_back(&pile, node);
		i++;
	}
	return (pile);
}
