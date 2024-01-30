/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:38:14 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:10 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*
	 * 1- analyser la pile : si dans l'ordre et cb d'elem
	 * 2- DONE=> si un : rien faire
	 * 3- si deux : swap
	 * 4- si moins de trois elems : sort last three
	 * 5- si entre quatre ou cinq = sort last four || five
	 */

void	analyze_pile(long *numbers, int size, t_list **pa, t_list **pb)
{
	int	sorted;

	sorted = 0;
	if (size == 1)
		return ;
	if (numbers_in_order(numbers, size))
		return ;
	if (size == 2)
		ft_swap(pa, 'a');
	if (size == 3)
		sort_three(pa, 'a');
	if (size > 3)
	{
		req_one_action(pa, numbers, size, &sorted);
		if (size <= 5 && !sorted)
			sort_four_or_five(pa, pb, numbers);
		if (size > 5 && !sorted)
			algo_radix(pa, pb);
	}
}
