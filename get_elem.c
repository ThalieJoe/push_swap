/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:40:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:16 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_elem(char **argv)
{
	char	**elements;
	int		i;
	int		nofelem;

	i = 1;
	while (argv[i])
		i++;
	nofelem = i - 1;
	if (nofelem == 1)
	{
		elements = ft_split(argv[1], "\t\n\v\f ");
		return (elements);
	}
	elements = (char **)malloc((nofelem + 1) * sizeof(char *));
	if (elements == NULL)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		elements[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	elements[i - 1] = NULL;
	return (elements);
}
