/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:31:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 14:09:33 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_list **pile, char c)
{
	t_list	*last;
	int		first;
	int		second;
	int		third;

	if (pile == NULL || *pile == NULL || ft_lstsize(*pile) < 3)
		return ;
	last = ft_lstlast(*pile);
	first = *(int *)(*pile)->content;
	second = *(int *)((*pile)->next->content);
	third = *(int *)(last->content);
	if (first < second && first > third)
		ft_reverse_rotate(pile, c);
	if (second < third && first > third)
		ft_rotate(pile, c);
	if (first > second && first < third)
		ft_swap(pile, c);
	if (first > second && second > third)
	{	
		ft_rotate(pile, c);
		ft_swap(pile, c);
	}
	if (second > third && first < third)
	{
		ft_swap(pile, c);
		ft_rotate(pile, c);
	}
}
