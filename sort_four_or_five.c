/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_or_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:17:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:03 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	before_push_a(t_list **pa, t_list **pb, int *can_reverse_a)
{
	t_list	*last;

	while (*(int *)((*pb)->content) > *(int *)((*pa)->content))
	{
		*can_reverse_a += 1;
		ft_rotate(pa, 'a');
		last = ft_lstlast(*pa);
	}
	last = ft_lstlast(*pa);
	while (*(int *)((*pb)->content) < *(int *)(last->content)
			&& *can_reverse_a > 0)
	{
		*can_reverse_a -= 1;
		ft_reverse_rotate(pa, 'a');
		last = ft_lstlast(*pa);
	}
}

static void	after_push_a(t_list **pa)
{
	t_list	*last;

	last = ft_lstlast(*pa);
	while (*(int *)((*pa)->content) > *(int *)(last->content))
	{
		ft_reverse_rotate(pa, 'a');
		last = ft_lstlast(*pa);
	}
}

void	sort_four_or_five(t_list **pa, t_list **pb, long *numbers)
{
	int		max;
	int		can_reverse_a;

	can_reverse_a = 0;
	max = get_max(numbers, ft_lstsize(*pa));
	while (ft_lstsize(*pa) > 3)
	{
		if (*(int *)(*pa)->content == max)
			ft_rotate(pa, 'a');
		ft_push(pa, pb, 'b');
	}
	sort_three(pa, 'a');
	if (ft_lstsize(*pb) > 1
		&& *(int *)((*pb)->content) < *(int *)((*pb)->next->content))
		ft_swap(pb, 'b');
	while (ft_lstsize(*pb) > 0)
	{
		before_push_a(pa, pb, &can_reverse_a);
		ft_push(pb, pa, 'a');
	}
	after_push_a(pa);
}
