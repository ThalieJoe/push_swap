/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:54:31 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/15 13:09:14 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	need_swap_a(t_list **pile)
{
	t_list	*second;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return (0);
	second = (*pile)->next;
	if (*(int *)(second->content) < *(int *)((*pile)->content))
		return (1);
	return (0);
}

int	need_swap_b(t_list **pile)
{
	t_list	*second;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return (0);
	second = (*pile)->next;
	if (*(int *)(second->content) > *(int *)((*pile)->content))
		return (1);
	return (0);
}
