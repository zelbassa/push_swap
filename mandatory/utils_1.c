/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:59 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/26 15:55:14 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (i > 10)
			return (0);
		i++;
	}
	return (1);
}

int	within_range(const char *str)
{
	const char	*max;
	const char	*min;

	max = "2147483647";
	min = "-2147483648";
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10 && ft_strcmp(str, max) > 0)
		return (0);
	if (ft_strlen(str) == 11 && ft_strcmp(str, min) > 0)
		return (0);
	return (1);
}

void	free_stack(int **stack)
{
	free(*stack);
	*stack = NULL;
}

int	is_sorted(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if ((*stack)[i] > (*stack)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	finish_sort(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	max_index;
	int	length;

	length = *len_b + *len_a;
	while (*len_b > 0)
	{
		max_index = find_max(stack_b, *len_b);
		if (max_index <= *len_b / 2)
			push_up(stack_b, len_b, max_index);
		else
			push_down(stack_b, len_b, *len_b - max_index);
		pa(stack_a, stack_b, len_b, len_a);
	}
}
