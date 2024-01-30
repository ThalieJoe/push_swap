/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:57:35 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 15:29:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_number(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	beyond_limits(const char *nptr)
{
	long	res;
	int		i;
	int		sg;

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

static int	without_zero(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

int	is_error(char **elem)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (elem[i] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (elem[i] != NULL)
	{
		str = ft_strtrim(elem[i], "\t\n\v\f ");
		j = without_zero(elem[i]);
		if (ft_strlen(str + j) > 11 || is_not_number(str)
			|| beyond_limits(str) || is_dup(elem, i))
		{
			free(str);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		free(str);
		i++;
	}
	return (0);
}
