/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:00:45 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 16:04:23 by prizmo           ###   ########.fr       */
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