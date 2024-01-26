/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:30:15 by stouitou          #+#    #+#             */
/*   Updated: 2023/12/08 12:28:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	*lst = NULL;
}

void	st_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL || lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		st_lstdelone(tmp);
		tmp = next;
	}
	*lst = NULL;
}
