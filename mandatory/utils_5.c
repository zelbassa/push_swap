/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:00:45 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/24 20:49:43 by zelbassa         ###   ########.fr       */
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
	exit(1);
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
	exit(1);
}

void	sort_four(int **stack_a, int **stack_b, int	*len_a, int *len_b)
{
	int	min_index;

	min_index = find_min(stack_a, 4);
	if (min_index < 2)
	{
		if (min_index == 1)
			sa(stack_a, 4);
		if (!is_sorted(stack_a, 4))
			pb(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	else
	{
		if (min_index == 2)
			rra(stack_a, 4);
		rra(stack_a, 4);
		if (!is_sorted(stack_a, 4))
			pb(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	sort_three(stack_a, 'a');
	pa(stack_a, stack_b, len_b, len_a);
}

void	sort_five(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	min_index;

	min_index = find_min(stack_a, 5);
	if (min_index < 2)
	{
		if (min_index == 1)
			sa(stack_a, 5);
		if (!is_sorted(stack_a, 5))
			pb(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	else
	{
		if (min_index == 2)
			rra(stack_a, 5);
		rra(stack_a, 5);
		if (!is_sorted(stack_a, 5))
			pb(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	sort_four(stack_a, stack_b, len_a, len_b);
	pa(stack_a, stack_b, len_b, len_a);
}

void	pre_sort_b(int **stack_b, int len_b)
{
	if ((*stack_b)[0] < (*stack_b)[1])
		sb(stack_b, len_b);
}
