/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:06 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 12:16:43 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elem(char **elem)
{
	int	count;

	count = 0;
	while (elem[count])
		count++;
	return (count);
}

long	get_min(long *arr, int size)
{
	long	min;
	int		i;

	i = 0;
	min = arr[i];
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

long	get_max(long *arr, int size)
{
	long	max;
	int		i;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_pile(t_list **pile)
{
	t_list	*next;

	if (pile == NULL || *pile == NULL)
		return ;
	while (*pile)
	{
		next = (*pile)->next;
		free(*pile);
		*pile = next;
	}
	*pile = NULL;
}
