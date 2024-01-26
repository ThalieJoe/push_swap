/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:32:01 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 16:13:15 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*get_numbers(char **elem, int size)
{
	int	*numbers;
	int	i;

	numbers = (int *)malloc(sizeof(int) * size);
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

