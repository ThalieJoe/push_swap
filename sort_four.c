/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:17:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 13:56:59 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_four(t_list **pile_a, t_list **pile_b, int *numbers)
{
	int	can_reverse_a;
	int	max;
	t_list	*last;

	can_reverse_a = 0;
	max = get_max(numbers, ft_lstsize(*pile_a));
	while (ft_lstsize(*pile_a) > 3)
	{
		if (*(int *)(*pile_a)->content == max)
			ft_rotate(pile_a, 'a');
		ft_push(pile_a, pile_b, 'b');
	}
	sort_three(pile_a, 'a');
	if (ft_lstsize(*pile_b) > 1
		&& *(int *)((*pile_b)->content) < *(int *)((*pile_b)->next->content))
		ft_swap(pile_b, 'b');
	while (ft_lstsize(*pile_b) > 0)
	{
		while (*(int *)((*pile_b)->content) > *(int *)((*pile_a)->content))
		{
			can_reverse_a++;
			ft_rotate(pile_a, 'a');
		}
		last = ft_lstlast(*pile_a);
		while (*(int *)((*pile_b)->content) < *(int *)(last->content)
			&& can_reverse_a)
		{
			can_reverse_a--;
			ft_reverse_rotate(pile_a, 'a');
			last = ft_lstlast(*pile_a);
		}
		ft_push(pile_b, pile_a, 'a');
	}
	last = ft_lstlast(*pile_a);
	while (*(int *)((*pile_a)->content) > *(int *)(last->content))
	{
		ft_reverse_rotate(pile_a, 'a');
		last = ft_lstlast(*pile_a);
	}
}
