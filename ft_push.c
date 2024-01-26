/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:40:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 14:16:02 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_push(t_list **pile_a, t_list **pile_b, char l)
{
	t_list	*anext;
	t_list	*newb;

	if (pile_a == NULL || *pile_a == NULL)
		return ;
	anext = (*pile_a)->next;
	newb = *pile_a;
	newb->next = *pile_b;
	*pile_b = newb;
	*pile_a = anext;
	if (l == 'a')
		ft_printf("%s\n", "pa");
	if (l == 'b')
		ft_printf("%s\n", "pb");
}
