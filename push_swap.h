/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:02:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 16:49:16 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		main(int argc, char **argv);
char	**get_elem(char **argv);
int		is_error(char **elem);
long	*get_numbers(char **elem, int size);
t_list	*fill_pile(long *numbers, int size);
void	analyze_pile(long *numbers, int size, t_list **pa, t_list **pb);
int		numbers_in_order(long *numbers, int size);
void	sort_three(t_list **pile, char c);
void	req_one_action(t_list **pile, long *numbers, int size, int *sorted);
void	sort_four_or_five(t_list **pa, t_list **pb, long *numbers);
void	algo_radix(t_list **pa, t_list **pb);
void	counting_sort(long *stack, int size, long pos);
long	*initialize_stack(t_list *pile, int size);
void	sort_pile(t_list **pa, t_list **pb, long *stack, int size);
void	ft_swap(t_list **pile, char l);
void	ft_swap_both(t_list **pa, t_list **pb);
void	ft_push(t_list **pb, t_list **pa, char l);
void	ft_rotate(t_list **pile, char l);
void	ft_rotate_both(t_list **pa, t_list **pb);
void	ft_reverse_rotate(t_list **pile, char l);
void	ft_reverse_rotate_both(t_list **pa, t_list **pb);
/* in utils.c */
int		count_elem(char **elem);
long	get_min(long *arr, int size);
long	get_max(long *arr, int size);
void	free_tab(char **tab);
void	clear_pile(t_list **pile);

#endif
