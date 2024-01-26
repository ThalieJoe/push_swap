/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:02:44 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/22 15:24:04 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <time.h>

// RANDOM GENERATOR
char	**random_generator(char **argv)
{
	int	i;
	int	j;
	int	random_argv;
	int	array[1000];

	srand(time(NULL));
	random_argv = 12; //rand() % 100 + 5;
	i = 1;
	while (i <= random_argv)
	{
		array[i] = rand() % 200 - 100;
		j = 1;
		while (j < i)
		{
			if (array[i] == array[j])
			{
				array[i] = rand() % 10000 - 5000;
				j = 0;
			}
			j++;
		}
		argv[i] = ft_itoa(array[i]);
		ft_printf("%s ", argv[i]);
		i++;
	}
	ft_printf("\n");
	argv[i] = NULL;
	return (argv);
}
