/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:34:00 by stouitou          #+#    #+#             */
/*   Updated: 2023/12/08 15:49:02 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nwlst;
	t_list	*nwelem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	nwlst = NULL;
	while (lst)
	{
		nwelem = (t_list *)malloc(sizeof(t_list));
		if (nwelem == NULL)
		{
			ft_lstclear(&nwlst, del);
			return (NULL);
		}
		nwelem->content = f(lst->content);
		nwelem->next = NULL;
		if (nwlst == NULL)
			nwlst = nwelem;
		else
			ft_lstadd_back(&nwlst, nwelem);
		lst = lst->next;
	}
	return (nwlst);
}
