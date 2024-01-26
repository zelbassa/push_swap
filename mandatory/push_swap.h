/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:59:17 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/25 00:32:34 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_chunk_sort_data
{
	int	**stack_a;
	int	**stack_b;
	int	*len_a;
	int	*len_b;
	int	*sorted_stack;
	int	chunk_start;
	int	chunk_end;
	int	length;
}		t_chunk_sort_data;

int		*selection_sort(int arr[], int size);
void	sa(int **stack_a, int len_a);
void	sb(int **stack_b, int len_b);
void	ra(int **stack_a, int len_a);
void	rb(int **stack_b, int len_b);
void	rra(int **stack_a, int len_a);
void	rrb(int **stack_b, int len_b);
void	pb(int **src, int **dest, int *len_src, int *len_dest);
void	pa(int **dest, int **src, int *len_src, int *len_dest);
void	multiple_args(char **av, int ac, int **stack);
int		single_arg(char **av, int **stack);
int		set_tokens(char **tokens);
void	pre_sort_b(int **stack_b, int len_b);
void	push_down(int **stack_b, int *len_b, int index);
void	push_up(int **stack_b, int *len_b, int index);
int		ft_sqrt(int nb);
void	chunk_sort(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	get_sorted_stack(int **sorted_stack, int **stack_a, int len);
void	sort_two(int **stack_a, int len, char id);
void	sort_three(int **stack, char id);
void	sort_four(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	sort_five(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		is_sorted(int **stack, int len);
int		is_int(char *str);
void	finish_sort(int **stack_a, int **stack_b, int *len_a, int *len_b);
int		find_max(int **stack, int len);
int		find_min(int **stack, int len);
int		within_range(const char *str);
void	free_stack(int **stack);
int		has_duplicates(int **stack, int len);
void	error(void);
void	fill_b(int **stack_b, int len);
void	sort(int **stack_a, int **stack_b, int len);
void	fill_elements(char *av, int **stack, int *i);
void	sort_descending(int **stack_a, int **stack_b, int len);
int		is_rev_sorted(int **stack, int len);

#endif
