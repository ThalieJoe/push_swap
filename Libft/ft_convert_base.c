/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:57:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 16:17:10 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_n(char *n, char *base)
{
	int	i;

	i = 0;
	while (n[i] == 32 || (n[i] > 8 && n[i] < 14))
		i++;
	if (n[i] == '+' || n[i] == '-')
		i++;
	while (n[i])
	{
		if (!ft_ischarset(n[i], base))
			return (0);
		i++;
	}
	return (1);
}

static int	check_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) < 2)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j] || str[i] == '+' || str[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	char	*result;
	int		nb;

	if (!check_n(n, base_from))
		return (NULL);
	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(n, base_from);
	result = ft_itoa_base(nb, base_to);
	return (result);
}
