/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:38:42 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 14:16:23 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate(t_list **pile, char l)
{
	t_list	*new;
	t_list	*tmp;

	if (pile == NULL || *pile == NULL)
		return ;
	new = (*pile)->next;
	tmp = *pile;
	while ((*pile)->next)
		*pile = (*pile)->next;
	tmp->next = NULL;
	(*pile)->next = tmp;
	*pile = new;
	if (l == 'a')
		ft_printf("%s\n", "ra");
	else if (l == 'b')
		ft_printf("%s\n", "rb");
}

void	ft_rotate_both(t_list **pile_a, t_list **pile_b)
{	
	if (pile_a == NULL || *pile_a == NULL
		|| pile_b == NULL || *pile_b == NULL)
		return ;
	ft_rotate(pile_a, 'z');
	ft_rotate(pile_b, 'z');
	ft_printf("%s\n", "rr");
}
