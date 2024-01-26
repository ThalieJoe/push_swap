/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:00:42 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/24 16:23:34 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_pile(t_list **pile_a, t_list **pile_b, int *stack, int size)
{
	int	*a;
	int	*b;
	int	max;
	int	i;
	int	j;
	int	pos;
	int	k;
	int	alen;
	int	blen;

	a = (int *)malloc(size * sizeof(int));
	if (a == NULL)
		return ;
	b = (int *)malloc(size * sizeof(int));
	if (b == NULL)
		return ;
	max = get_max(stack, size);
	pos = 1;
	while (max / pos > 0)
	{
//		divide_pile();
		i = 0;
		j = 0;
		k = 0;
		while (i < size)
		{
			if ((stack[i] / pos) % 10 == 0)
			{
				b[j] = stack[i];
				j++;
				ft_push(pile_a, pile_b, 'b');
			}
			else
			{
				a[k] = stack[i];
				k++;
				ft_rotate(pile_a, 'a');
			}
			i++;
		}
		alen = k;
		blen = j;
		i = 0;
		k = 0;
		j = 0;
		while (j < blen)
		{
			stack[i] = b[j];
			ft_push(pile_b, pile_a, 'a');
			i++;
			j++;
		}
		while (k < alen)
		{
			stack[i] = a[k];
			i++;
			k++;
		}
		pos *= 10;
	}
	free(a);
	free(b);
}
