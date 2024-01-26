/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:58 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 15:18:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_lists(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		i;

	if (ft_lstsize(*pile_a) >= ft_lstsize(*pile_b))
		i = ft_lstsize(*pile_a);
	else
		i = ft_lstsize(*pile_b);
	tmpa = *pile_a;
	tmpb = *pile_b;
	while (i)
	{
		if (tmpa && tmpb)
			ft_printf("%d  %d\n", *(int *)tmpa->content, *(int *)tmpb->content);
		else if (tmpa)
			ft_printf("%d  \n", *(int *)tmpa->content);
		else if (tmpb)
			ft_printf("  %d\n", *(int *)tmpb->content);
		if (tmpa)
			tmpa = tmpa->next;
		if (tmpb)
			tmpb = tmpb->next;
		i--;
	}
	ft_printf(" -    - \n a    b \n");
}
