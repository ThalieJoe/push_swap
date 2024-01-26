/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:59:13 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 14:16:44 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **pile, char l)
{
	t_list	*tmp;
	t_list	*old;
	t_list	*stop;

	if (pile == NULL || *pile == NULL)
		return ;
	old = *pile;
	tmp = *pile;
	while (tmp->next)
		tmp = tmp->next;
	stop = tmp;
	tmp->next = old;
	*pile = tmp;
	while (tmp->next != stop)
		tmp = tmp->next;
	tmp->next = NULL;
	if (l == 'a')
		ft_printf("%s\n", "rra");
	if (l == 'b')
		ft_printf("%s\n", "rrb");
}

void	ft_reverse_rotate_both(t_list **pile_a, t_list **pile_b)
{
	if (pile_a == NULL || *pile_a == NULL
		|| pile_b == NULL || *pile_b == NULL)
		return ;
	ft_reverse_rotate(pile_a, 'c');
	ft_reverse_rotate(pile_b, 'c');
	ft_printf("%s\n", "z");
}
