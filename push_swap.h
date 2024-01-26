/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:02:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/25 15:50:23 by stouitou         ###   ########.fr       */
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
int	*get_numbers(char **elem, int size);
t_list	*fill_pile(int *elem, int size);
void	print_lists(t_list **pile_a, t_list **pile_b);
void	ft_swap(t_list **pile, char l);
void	ft_swap_both(t_list **pile_a, t_list **pile_b);
void	ft_push(t_list **pile_b, t_list **pile_a, char l);
void	ft_rotate(t_list **pile, char l);
void	ft_rotate_both(t_list **pile_a, t_list **pile_b);
void	ft_reverse_rotate(t_list **pile, char l);
void	ft_reverse_rotate_both(t_list **pile_a, t_list **pile_b);
void	analyze_elem(int *numbers, int size, t_list **pile_a, t_list **pile_b);
void	algo_radix(t_list **pile_a, t_list **pile_b);
void	counting_sort(int *stack, int size, int pos);
int		*initialize_stack(t_list **pile, int size);
void	sort_pile(t_list **pile_a, t_list **pile_b, int *stack, int size);
int		algo_pets(t_list **pile_a, t_list **pile_b);
void	sort_three(t_list **pile, char c);
void	sort_four(t_list **pile_a, t_list **pile_b, int *numbers);
void	requires_min_action(t_list **pile, int *numbers, int size, int *sorted);
int		need_rotate(t_list **pile);
int		need_reverse_rotate(t_list **pile);
int		need_swap_a(t_list **pile);
int		need_swap_b(t_list **pile);
int		numbers_in_order(int *numbers);
/* in utils.c */
int		count_elem(char **elem);
int		get_min(int *arr, int size);
int		get_max(int *arr, int size);
void	free_tab(char **tab);
void	delete_content(void *content);

char	**random_generator(char **argv);

#endif
