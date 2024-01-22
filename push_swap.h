/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:59:17 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 15:57:59 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

int		*selection_sort(int arr[], int size);
void	sa(int **stack_a, int len_a);
void	sb(int **stack_b, int len_b);
void	ra(int **stack_a, int len_a);
void	rb(int **stack_b, int len_b);
void	rra(int	**stack_a, int len_a);
void	rrb(int	**stack_b, int len_b);
void	pb(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	pa(int **stack_a, int **stack_b, int *len_a, int *len_b);
void	multiple_args(char **av, int ac, int **stack);
void	single_arg(char **av, int **stack);
int		set_tokens(int **tokens, int **av);

#endif
