/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:00:42 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:01 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct sort_list
{
	int	*a;
	int	*b;
	int	max;
	int	pos;
	int	size;
	int	alen;
	int	blen;
	int	i;
	int	j;
	int	k;
}	t_pets;

static void	initialize_indexes(t_pets *tab)
{
	tab->i = 0;
	tab->j = 0;
	tab->k = 0;
}

static void	sort_p3(t_list **pa, t_list **pb, long *stack, t_pets *tab)
{
	initialize_indexes(tab);
	while (tab->i < tab->size)
	{
		if ((stack[tab->i] / tab->pos) % 10 == 0)
		{
			tab->b[tab->j] = stack[tab->i];
			ft_push(pa, pb, 'b');
			tab->j++;
		}
		else
		{
			tab->a[tab->k] = stack[tab->i];
			ft_rotate(pa, 'a');
			tab->k++;
		}
		tab->i++;
	}
	tab->alen = tab->k;
	tab->blen = tab->j;
}

static void	sort_p2(t_list **pa, t_list **pb, long *stack, t_pets *tab)
{
	while (tab->max / tab->pos > 0)
	{
		sort_p3(pa, pb, stack, tab);
		initialize_indexes(tab);
		while (tab->j < tab->blen)
		{
			stack[tab->i] = tab->b[tab->j];
			ft_push(pb, pa, 'a');
			tab->i++;
			tab->j++;
		}
		while (tab->k < tab->alen)
		{
			stack[tab->i] = tab->a[tab->k];
			tab->i++;
			tab->k++;
		}
		tab->pos *= 10;
	}
}

void	sort_pile(t_list **pa, t_list **pb, long *stack, int size)
{
	t_pets	*tab;

	tab = (t_pets *)malloc(sizeof(t_pets));
	if (!tab)
		return ;
	tab->a = (int *)malloc(size * sizeof(int));
	if (tab->a == NULL)
		return ;
	tab->b = (int *)malloc(size * sizeof(int));
	if (tab->b == NULL)
		return ;
	tab->size = size;
	tab->max = get_max(stack, size);
	tab->pos = 1;
	sort_p2(pa, pb, stack, tab);
	free(tab->a);
	free(tab->b);
	free(tab);
}
