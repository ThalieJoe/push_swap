/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:32:01 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 12:16:09 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*get_numbers(char **elem, int size)
{
	long	*numbers;
	int		i;

	numbers = (long *)malloc(sizeof(long int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (elem[i])
	{
		numbers[i] = ft_atoi(elem[i]);
		i++;
	}
	return (numbers);
}
