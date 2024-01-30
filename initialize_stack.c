/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:12 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 12:25:23 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*initialize_stack(t_list *pile, int size)
{
	t_list	*tmp;
	long	*arr;
	int		i;

	if (pile == NULL)
		return (NULL);
	tmp = pile;
	arr = (long *)malloc(sizeof(long) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = *((long *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
