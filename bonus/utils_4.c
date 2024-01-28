/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:30:33 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 18:03:14 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb_b(int **stack_b, int len_b)
{
	int	tmp;

	if (len_b < 2)
		return ;
	tmp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
}

void	ra_b(int **stack_a, int len_a)
{
	int	i;
	int	tmp;

	i = 0;
	if (len_a < 2)
		return ;
	tmp = (*stack_a)[0];
	while (i < len_a - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	(*stack_a)[len_a - 1] = tmp;
}

void	rb_b(int **stack_b, int len_b)
{
	int	i;
	int	tmp;

	i = 0;
	if (len_b < 2)
		return ;
	tmp = (*stack_b)[0];
	while (i < len_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	(*stack_b)[len_b - 1] = tmp;
}

void	rra_b(int	**stack_a, int len_a)
{
	int	i;
	int	tmp;

	if (len_a < 2)
		return ;
	i = len_a - 1;
	tmp = (*stack_a)[len_a - 1];
	while (i > 0)
	{
		(*stack_a)[i] = (*stack_a)[i - 1];
		i--;
	}
	(*stack_a)[0] = tmp;
}

void	rrb_b(int	**stack_b, int len_b)
{
	int	i;
	int	tmp;

	i = len_b - 1;
	tmp = (*stack_b)[len_b - 1];
	if (len_b < 2)
		return ;
	while (i > 0)
	{
		(*stack_b)[i] = (*stack_b)[i - 1];
		i--;
	}
	(*stack_b)[0] = tmp;
}
