/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:10:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/22 12:52:39 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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

void	fill_number(size_t nb, char *number, char *base, int i)
{
	number[i] = '\0';
	i--;
	while (nb >= ft_strlen(base))
	{
		number[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i--;
	}
	number[i] = base[nb % ft_strlen(base)];
}

char	*ft_itoa_base(int n, char *base)
{
	char		*number;
	long int	nb;
	int			i;

	nb = n;
	if (!check_base(base))
		return (NULL);
	number = (char *)malloc((ft_nbrlen_base(nb, base) + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	i = ft_nbrlen_base(nb, base);
	if (nb < 0)
	{
		number[0] = '-';
		nb = -nb;
	}
	fill_number(nb, number, base, i);
	return (number);
}
