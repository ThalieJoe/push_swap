/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:46:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/15 12:46:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	need_reverse_rotate(t_list **pile)
{
	t_list	*tmp;
	t_list	*last;

	if (pile == NULL || *pile == NULL)
		return (0);
	tmp = *pile;
	last = ft_lstlast(tmp);
	if (*(int *)(tmp->content) > *(int *)(last->content))
		return (1);
	return (0);
}
