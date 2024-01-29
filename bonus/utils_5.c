/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:31:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 17:40:39 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(int **stack_a, int **stack_b, int len_a, int len_b)
{
	rra_b(stack_a, len_a);
	rrb_b(stack_b, len_b);
}

void	rr(int **stack_a, int **stack_b, int len_a, int len_b)
{
	ra_b(stack_a, len_a);
	rb_b(stack_b, len_b);
}

void	ss(int **stack_a, int **stack_b, int len_a, int len_b)
{
	sa_b(stack_a, len_a);
	sb_b(stack_b, len_b);
}

void    free_tokens(char **tokens)
{
    int	i;

    i = 0;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}