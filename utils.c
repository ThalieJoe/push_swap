/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:06 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 16:15:40 by stouitou         ###   ########.fr       */
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

int	get_min(int *arr, int size)
{
	int	min;
	int	i;

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

int	get_max(int *arr, int size)
{
	int	max;
	int	i;

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

void	delete_content(void *content)
{
	free(content);
}
