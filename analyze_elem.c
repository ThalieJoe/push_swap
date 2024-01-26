/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:38:14 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 14:27:37 by stouitou         ###   ########.fr       */
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

void	analyze_elem(int *numbers, int size, t_list **pile_a, t_list **pile_b)
{
	int	sorted;

	sorted = 0;
	if (size == 1)
		return ;
	if (numbers_in_order(numbers))
		return ;
	if (size == 2)
		ft_swap(pile_a, 'a');
	if (size == 3)
		sort_three(pile_a, 'a');
	if (size > 3)
		requires_min_action(pile_a, numbers, size, &sorted);
	if (size > 3 && size <= 5 && !sorted)
		sort_four(pile_a, pile_b, numbers);
	if (size > 5 && !sorted)
		algo_radix(pile_a, pile_b);
}
