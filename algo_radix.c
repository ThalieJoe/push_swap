/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:32:21 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:14 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Non-negative normalization */
static void	normalize(long *arr, int size, long min)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] -= min;
		i++;
	}
}

/* Back to original after normalization */
static void	denormalize(long *arr, int size, long min)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] += min;
		i++;
	}
}

static void	binary_index(long *stack, int size)
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
		free(i_base_dec);
		free(i_base_bin);
	}
}

static long	*radix_sort(t_list **pile, int size)
{
	long	*stack;
	long	min;
	long	max;
	long	i;

	stack = initialize_stack(*pile, size);
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

void	algo_radix(t_list **pa, t_list **pb)
{
	long	*stack;
	long	*tmp;
	int		i;
	int		j;
	int		size;

	size = ft_lstsize(*pa);
	tmp = radix_sort(pa, size);
	stack = initialize_stack(*pa, size);
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
	free(tmp);
	binary_index(stack, size);
	sort_pile(pa, pb, stack, size);
	free(stack);
}
