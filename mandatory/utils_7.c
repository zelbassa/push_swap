/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:30:48 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/24 20:46:18 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_elements(char *av, int **stack, int *i)
{
	char	**tokens;
	int		j;

	j = 0;
	tokens = ft_split(av, ' ');
	while (tokens[j])
	{
		if (is_int(tokens[j]) && within_range(tokens[j]))
		{
			(*stack)[*i] = ft_atoi(tokens[j]);
			j++;
			(*i)++;
		}
		else
			error();
	}
}

int	find_min(int **stack, int len)
{
	int	i;
	int	min_value;
	int	min_index;

	i = 0;
	min_value = (*stack)[0];
	min_index = 0;
	while (i < len)
	{
		if ((*stack)[i] < min_value)
		{
			min_value = (*stack)[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	set_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (tokens)
	{
		while (tokens[i])
		{
			if (is_int(tokens[i]) && within_range(tokens[i]))
				i++;
			else
				error();
		}
	}
	if (i < 2)
		return (0);
	return (i);
}

void	sort_descending(int **stack_a, int **stack_b, int len)
{
	int	i;
	int	min_index;
	int	len_a;
	int	len_b;

	len_a = len;
	len_b = 0;
	i = 0;
	while (len_a > 0)
	{
		min_index = find_min(stack_a, len_a);
		if (min_index < len_a / 2)
			while (min_index-- > 0)
				ra(stack_a, len_a);
		else
			while (min_index++ < len_a)
				rra(stack_a, len_a);
		pb(stack_a, stack_b, &len_a, &len_b);
	}
	while (len_b > 0)
		pa(stack_a, stack_b, &len_b, &len_a);
}
