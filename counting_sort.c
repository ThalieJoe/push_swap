/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:10:06 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_count(long *a, int size, long pos)
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

static void	update_a(long *a, long *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a[i] = b[i];
		i++;
	}
}

void	counting_sort(long *stack, int size, long pos)
{
	long	*a;
	long	*b;
	int		*count;
	int		i;

	if (stack == NULL || size == 0 || pos == 0)
		return ;
	a = stack;
	b = (long *)malloc(sizeof(long) * size);
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
	update_a(a, b, size);
	free(count);
	free(b);
}
