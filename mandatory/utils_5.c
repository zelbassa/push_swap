/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:00:45 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/26 10:05:15 by prizmo           ###   ########.fr       */
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
	}
	else
	{
		if (min_index == 2)
			rra(stack_a, 4);
		rra(stack_a, 4);
		if (!is_sorted(stack_a, 4))
			pb(stack_a, stack_b, len_a, len_b);
	}
	sort_three(stack_a, 'a');
	pa(stack_a, stack_b, len_b, len_a);
}

static int	find_second_min(int **stack, int len)
{
	int	i;
	int	min;
	int	second_min;

	i = 0;
	min = find_min(stack, len);
    second_min = find_max(stack, len);
	while (i < len)
	{
		if ((*stack)[i] > (*stack)[min] && (*stack)[i] < (*stack)[second_min])
            second_min = i;
        i++;
	}
	return (second_min);
}

void	sort_five(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	second_min;

    second_min = find_second_min(stack_a, 5);
    if (second_min <= 2)
    {
        while (second_min-- > 0)
            ra(stack_a, 5);
    }
    else
    {
        while (second_min++ < 5)
            rra(stack_a, 5);
    }
    pb(stack_a, stack_b, len_a, len_b);
    sort_four(stack_a, stack_b, len_a, len_b);
    pa(stack_a, stack_b, len_b, len_a);
    if ((*stack_a)[0] > (*stack_a)[1])
        sa(stack_a, 5);
}
