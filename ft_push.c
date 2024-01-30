/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:40:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:09 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **pa, t_list **pb, char l)
{
	t_list	*anext;
	t_list	*newb;

	if (pa == NULL || *pa == NULL)
		return ;
	anext = (*pa)->next;
	newb = *pa;
	newb->next = *pb;
	*pb = newb;
	*pa = anext;
	if (l == 'a')
		ft_printf("%s\n", "pa");
	if (l == 'b')
		ft_printf("%s\n", "pb");
}
