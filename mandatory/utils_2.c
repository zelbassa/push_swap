/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:24:31 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:27:29 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = (*stack_a)[0];
	while (i < *len_a - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	j = *len_b;
	i = 0;
	while (j > 0)
	{
		(*stack_b)[j] = (*stack_b)[j - 1];
		j--;
	}
	(*stack_b)[0] = tmp;
	(*len_a)--;
	(*len_b)++;
	(*stack_a)[*len_a - 1] = 0;
	ft_putstr("pb\n");
}

void	pa(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = (*stack_b)[0];
	while (i < *len_b - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	j = *len_a;
	i = 0;
	while (j > 0)
	{
		(*stack_a)[j] = (*stack_a)[j - 1];
		j--;
	}
	(*stack_a)[0] = tmp;
	(*len_b)--;
	(*len_a)++;
	(*stack_b)[*len_b - 1] = 0;
	ft_putstr("pa\n");
}

void	sa(int **stack_a, int len_a)
{
	int	tmp;

	if (len_a < 2)
		return ;
	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
	ft_putstr("sa\n");
}

void	sb(int **stack_b, int len_b)
{
	int	tmp;

	if (len_b < 2)
		return ;
	tmp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
	ft_putstr("sb\n");
}
