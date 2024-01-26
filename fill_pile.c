/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:38:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/23 15:55:56 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*fill_pile(int *elem, int size)
{
	t_list	*pile;
	int		i;
	t_list	*number;

	pile = NULL;
	i = 0;
	while (i < size)
	{
		number = ft_lstnew(&elem[i]);
		ft_lstadd_back(&pile, number);
		i++;
	}
	return (pile);
}
