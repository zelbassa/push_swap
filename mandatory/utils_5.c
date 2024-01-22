/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:00:45 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:27:35 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(int **stack_a, int len, char id)
{
	if ((*stack_a)[0] > (*stack_a)[1])
	{
		if (id == 'a')
			sa(stack_a, len);
		else
			sb(stack_a, len);
	}
}

void	sort_three(int **stack, char id)
{
	if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]))
	{
		if (id == 'a')
			ra(stack, 3);
		else
			rb(stack, 3);
	}
	if (((*stack)[1] > (*stack)[0]) && ((*stack)[1] > (*stack)[2]))
	{
		if (id == 'a')
			rra(stack, 3);
		else
			rrb(stack, 3);
	}
	if ((*stack)[0] > (*stack)[1])
	{
		if (id == 'a')
			sa(stack, 3);
		else
			sb(stack, 3);
	}
}

int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	pre_sort_b(int **stack_b, int len_b)
{
	if ((*stack_b)[0] < (*stack_b)[1])
		sb(stack_b, len_b);
}