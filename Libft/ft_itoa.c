/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:54:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 11:02:54 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long int	ft_valabs(long int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static char	*ft_intzero(void)
{
	char	*num;

	num = (char *)malloc(2 * sizeof(char));
	if (num == NULL)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*num;
	int			i;

	nb = n;
	if (nb == 0)
	{
		num = ft_intzero();
		return (num);
	}
	num = (char *)malloc((ft_nbrlen(nb) + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	i = ft_nbrlen(nb);
	num[i] = '\0';
	i--;
	if (nb < 0)
		num[0] = '-';
	nb = ft_valabs(nb);
	while (nb > 0)
	{
		num[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (num);
}
