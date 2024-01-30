/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:31:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:15 by stouitou         ###   ########.fr       */
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
	if (first > second && first > third)
		ft_rotate(pile, c);
	else if (second > first && second > third)
		ft_reverse_rotate(pile, c);
	first = *(int *)(*pile)->content;
	second = *(int *)((*pile)->next->content);
	if (first > second)
		ft_swap(pile, c);
}
