/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:31:04 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:27:31 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int **stack_a, int len_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = (*stack_a)[0];
	while (i < len_a - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	(*stack_a)[len_a - 1] = tmp;
	ft_putstr("ra\n");
}

void	rb(int **stack_b, int len_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = (*stack_b)[0];
	while (i < len_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	(*stack_b)[len_b - 1] = tmp;
	ft_putstr("rb\n");
}

void	rra(int	**stack_a, int len_a)
{
	int	i;
	int	tmp;

	i = len_a - 1;
	tmp = (*stack_a)[len_a - 1];
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = tmp;
	ft_putstr("rra\n");
}

void	rrb(int	**stack_b, int len_b)
{
	int	i;
	int	tmp;

	i = len_b - 1;
	tmp = (*stack_b)[len_b - 1];
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = tmp;
	ft_putstr("rrb\n");
}

int	find_max(int **stack, int length)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < length)
	{
		if ((*stack)[i] > (*stack)[max_index])
			max_index = i;
		i ++;
	}
	return (max_index);
}