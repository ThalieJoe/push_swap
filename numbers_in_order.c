/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_in_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:17 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:12 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	numbers_in_order(long *numbers, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (numbers[i - 1] > numbers[i])
			return (0);
		i++;
	}
	return (1);
}
