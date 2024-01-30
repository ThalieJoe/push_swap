/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:27:17 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:43:36 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**elem;
	t_list	*pa;
	t_list	*pb;
	long	*numbers;
	int		size;

	if (argc < 2
		|| (argc == 2 && argv[1][0] == '\0'))
		return (0);
	pb = NULL;
	elem = get_elem(argv);
	if (is_error(elem))
	{
		free_tab(elem);
		return (0);
	}
	size = count_elem(elem);
	numbers = get_numbers(elem, size);
	free_tab(elem);
	pa = fill_pile(numbers, size);
	analyze_pile(numbers, size, &pa, &pb);
	clear_pile(&pa);
	clear_pile(&pb);
	free(numbers);
	return (0);
}
