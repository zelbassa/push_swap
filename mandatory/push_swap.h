/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:59:17 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:34:04 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

int		*selection_sort(int arr[], int size);
void	sa(int **stack_a, int len_a);
void	sb(int **stack_b, int len_b);
void	ra(int **stack_a, int len_a);
void	rb(int **stack_b, int len_b);
void	rra(int	**stack_a, int len_a);
void	rrb(int	**stack_b, int len_b);
void	pb(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	pa(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		multiple_args(char **av, int ac, int **stack);
int		single_arg(char **av, int **stack);
int		set_tokens(char **tokens, int **av);
void	pre_sort_b(int **stack_b, int len_b);
void	push_down(int **stack_b, int *len_b, int index);
void	push_up(int **stack_b, int *len_b, int index);
int		ft_sqrt(int nb);
void	chunk_sort(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	get_sorted_stack(int **sorted_stack, int **stack_a, int len);
void	sort_two(int **stack_a, int len, char id);
void	sort_three(int **stack, char id);
int		is_sorted(int **stack, int len);
int		is_int(char *str);
void	finish_sort(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		find_max(int **stack, int len);

#endif
