/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:24:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 11:00:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_base_fd(int nb, char *base, int fd)
{
	long int	n;
	int			len;

	n = nb;
	len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= len)
		ft_putnbr_base_fd(n / len, base, fd);
	ft_putchar_fd(base[n % len], 1);
}
