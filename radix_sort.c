/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:32:21 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/24 16:22:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	normalize(int *arr, int size, int min)
{
	int	i;

	i = 0;
	min = -min;
	while (i < size)
	{
		arr[i] += min;
		i++;
	}
}

static void	denormalize(int *arr, int size, int min)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] += min;
		i++;
	}
}

static void	binary_index(int *stack, int size)
{
	int		i;
	char	*i_base_dec;
	char	*i_base_bin;

	i = 0;
	while (i < size)
	{
		i_base_dec = ft_itoa(stack[i]);
		i_base_bin = ft_convert_base(i_base_dec, "0123456789", "01");
		stack[i] = ft_atoi(i_base_bin);
		i++;
	}
}

static int	*radix_sort(t_list **pile, int size)
{
	int	*stack;
	int	min;
	int	max;
	int	i;

	stack = initialize_stack(pile, size);
	min = get_min(stack, size);
	if (min < 0)
		normalize(stack, size, min);
	max = get_max(stack, size);
	i = 1;
	while (max / i)
	{
		counting_sort(stack, size, i);
		i *= 10;
	}
	if (min < 0)
		denormalize(stack, size, min);
	return (stack);
}

void	algo_radix(t_list **pile_a, t_list **pile_b)
{
	int	*stack;
	int	*tmp;
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(*pile_a);
	tmp = radix_sort(pile_a, size);
	stack = initialize_stack(pile_a, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tmp[i] == stack[j])
				stack[j] = i;
			j++;
		}
		i++;
	}
	binary_index(stack, size);
	sort_pile(pile_a, pile_b, stack, size);
}
