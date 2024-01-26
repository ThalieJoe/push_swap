/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:14:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 15:25:47 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

	/* 
	 * PHASE 1
	 * 1- check rotate a
	 * 2- check rotate b
	 * 3- check swap a et b
	 * 4- pushb
	 * 5- check rotate et rev rotate a et b
	 * 6- and repeat check rotate / swap / push
	 * 7- until pile a has 3 items
	 * PHASE 2
	 * 1- put the last 3 items of pile_a in order and check pile_b at the same time
	 * PHASE 3
	 * 1- compare top of b with top of a
	 * 2- put a at the bottom of a if required
	 * 3- pusha
	 * 4- compare top of b with top of a AND bottom of a
	 * 5- reverse rotate a OR pusha
	 * 6- repeat 4 and 5 until the end 
	 * 7- clean up pile_a in case reverse rotations were needed
	 */

void	algo_pets(t_list **pile_a, t_list **pile_b)
{
	t_list	*last;
	int		can_reverse_a;
	int		result;

	result = 0;
	// PHASE 1
	while (ft_lstsize(*pile_a) > 3)
	{
		while (need_reverse_rotate(pile_a))
			ft_reverse_rotate(pile_a, 'a');
		if (need_rotate(pile_b))
			ft_rotate(pile_b, 'b');
		if (need_swap_a(pile_a) && need_swap_b(pile_b))
			ft_swap_both(pile_a, pile_b);
		else if (need_swap_a(pile_a))
			ft_swap(pile_a, 'a');
		else if (need_swap_b(pile_b))
			ft_swap(pile_b, 'b');
		ft_push(pile_a, pile_b, 'b');
	}
	print_lists(pile_a, pile_b);
	// PHASE 2
	sort_last_three(pile_a, 'a');
	if (need_rotate(pile_b))
		ft_rotate(pile_b, 'b');
	if (need_swap_b(pile_b))
		ft_swap(pile_b, 'b');
	if (need_rotate(pile_b))
		ft_rotate(pile_b, 'b');
	print_lists(pile_a, pile_b);
	// PHASE 3
	can_reverse_a = 0;
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
