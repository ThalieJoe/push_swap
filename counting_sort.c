/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:10:06 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 16:35:15 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	*fill_count(int *a, int size, int pos)
{
	int	*count;
	int	i;

	if (a == NULL || size == 0 || pos == 0)
		return (NULL);
	i = 0;
	count = (int *)ft_calloc(10, sizeof(int));
	if (count == NULL)
		return (NULL);
	while (i < size)
	{
		count[(a[i] / pos) % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	return (count);
}

void	counting_sort(int *stack, int size, int pos)
{
	int	*a;
	int	*b;
	int	*count;
	int	i;

	if (stack == NULL || size == 0 || pos == 0)
		return ;
	a = stack;
	b = (int *)malloc(sizeof(int) * size);
	if (b == NULL)
		return ;
	count = fill_count(a, size, pos);
	i = size - 1;
	while (i >= 0)
	{
		count[(a[i] / pos) % 10]--;
		b[count[(a[i] / pos) % 10]] = a[i];
		i--;
	}
	i = 0;
	while (i < size)
	{
		a[i] = b[i];
		i++;
	}
}
