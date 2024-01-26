/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:56:05 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/26 10:05:34 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_up(int **stack_b, int *len_b, int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return ;
	while (i < index)
	{
		rb(stack_b, *len_b);
		i ++;
	}
}

void	push_down(int **stack_b, int *len_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rrb(stack_b, *len_b);
		i ++;
	}
}

void	fill_b(int **stack_b, int len)
{
	while (len-- > 0)
		(*stack_b)[len] = 0;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	pre_sort_b(int **stack_b, int len_b)
{
	if ((*stack_b)[0] < (*stack_b)[1])
		sb(stack_b, len_b);
}
