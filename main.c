/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:27:17 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 16:26:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_not_number(char *str)
{
	int		i;
	char	*s;
	char	*charset;

	i = 0;
	charset	= "\t\n\v\f ";
	s = ft_strtrim(str, charset);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	free(s);
	return (0);
}

static int	beyond_limits(const char *nptr)
{
	long int	res;
	int			i;
	int			sg;

	res = 0;
	i = 0;
	sg = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (sg * res < -2147483648 || sg * res > 2147483647)
		return (1);
	return (0);
}

static int	is_dup(char **elements, int i)
{
	int	j;

	if (i == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		if (ft_atoi(elements[j]) == ft_atoi(elements[i]))
			return (1);
		j++;
	}
	return (0);
}

static int	is_error(char **elem)
{
	int	i;

	i = 0;
	if (elem[i] == 	NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (elem[i] != NULL)
	{
		if (is_not_number(elem[i])
			|| beyond_limits(elem[i])
			|| is_dup(elem, i))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**elem;
	t_list	*pile_a;
	t_list	*pile_b;
	int	*numbers;
	int	size;
	int	i;
	i = 0;	
	if (argc < 2)
		return (0);
	pile_b = NULL;
	elem = get_elem(argv);
	if (is_error(elem))
		return (0);
	size = count_elem(elem);
	numbers = get_numbers(elem, size);
	free_tab(elem);
	pile_a = fill_pile(numbers, size);
	analyze_elem(numbers, size, &pile_a, &pile_b);
	if (pile_a)
		st_lstclear(&pile_a);
	if (pile_b)
		st_lstclear(&pile_b);
	free(numbers);
	return (0);
}
