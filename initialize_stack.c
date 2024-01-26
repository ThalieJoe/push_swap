/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:12 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 15:58:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*initialize_stack(t_list **pile, int size)
{
	t_list	*tmp;
	int		*arr;
	int		i;

	if (pile == NULL || *pile == NULL)
		return (NULL);
	tmp = *pile;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = *((int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
