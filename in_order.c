/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:02:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 15:29:27 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	numbers_in_order(int *numbers)
{
	int	i;

	i = 1;
	while (numbers[i])
	{
		if (numbers[i - 1] > numbers[i])
			return (0);
		i++;
	}
	return (1);
}

int	*extract_middle(int *numbers, int size)
{
	int	*middle;
	int	i;

	middle = (int *)malloc((size - 3) * sizeof(int));
	if (middle == NULL)
		return (NULL);
	i = 2;
	while (i < size - 1)
	{
		middle[i - 2] = numbers[i];
		i++;
	
	}
	return (middle);
}

int	need_one_rotate(t_list **pile, int min, int max, int *sorted)
{
	int		first;
	int		second;
	int		last;
	t_list	*third;

	third = ft_lstlast(*pile);
	first = *(int *)(*pile)->content;
	second = *(int *)(*pile)->next->content;
	last = *(int *)third->content;
	if (second < min && last > max && last < first)
	{	
		*sorted = 1;
		return (1);
	}
	return (0);
}

int	need_one_reverse_rotate(t_list **pile, int min, int *sorted)
{
	int		first;
	int		second;
	int		last;
	t_list	*third;

	third = ft_lstlast(*pile);
	first = *(int *)(*pile)->content;
	second = *(int *)(*pile)->next->content;
	last = *(int *)third->content;
	if (second < min && last < first && first < second)
	{	
		*sorted = 1;
		return (1);
	}
	return (0);
}

int	need_one_swap(t_list **pile, int min, int max, int *sorted)
{
	int		first;
	int		second;
	int		last;
	t_list	*third;

	third = ft_lstlast(*pile);
	first = *(int *)(*pile)->content;
	second = *(int *)(*pile)->next->content;
	last = *(int *)third->content;
	if (second < first && first < min && last > max)
	{	
		*sorted = 1;
		return (1);
	}
	return (0);
}

void	requires_min_action(t_list **pile, int *numbers, int size, int *sorted)
{
	t_list	*last;
	int		*middle;
	int		min;
	int		max;

	last = ft_lstlast(*pile);
	middle = extract_middle(numbers, size);
	if (!numbers_in_order(middle))
	{
		free(middle);
		return ;
	}
	min = get_min(middle, size - 3);
	max = get_max(middle, size - 3);
	if (need_one_rotate(pile, min, max, sorted))
		ft_rotate(pile, 'a');
	if (need_one_reverse_rotate(pile, min, sorted))
		ft_reverse_rotate(pile, 'a');
	if (need_one_swap(pile, min, max, sorted))
		ft_swap(pile, 'a');
	free(middle);
}
