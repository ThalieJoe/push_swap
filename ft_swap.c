/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:57:42 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:05 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **pile, char l)
{
	t_list	*tmp;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return ;
	tmp = *pile;
	a = tmp;
	b = tmp->next;
	c = tmp->next->next;
	a->next = c;
	b->next = a;
	tmp = b;
	*pile = tmp;
	if (l == 'a')
		ft_printf("%s\n", "sa");
	else if (l == 'b')
		ft_printf("%s\n", "sb");
}

void	ft_swap_both(t_list **pa, t_list **pb)
{
	if (pa == NULL || *pa == NULL
		|| pb == NULL || *pb == NULL)
		return ;
	ft_swap(pa, 'z');
	ft_swap(pb, 'z');
	ft_printf("%s\n", "ss");
}
