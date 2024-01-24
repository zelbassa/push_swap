/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:30:48 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/24 15:56:24 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_elements(char *av, int **stack, int *i)
{
	char	**tokens;
	int		k;

	k = 0;
	tokens = ft_split(av, ' ');
	while (tokens[k])
	{
		if (is_int(tokens[k]) && within_range(tokens[k]))
		{
			(*stack)[*i] = ft_atoi(tokens[k]);
			k ++;
			*i += 1;
		}
		else
		{
			free_stack(stack);
			error();
		}
	}
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
				return (0);
		}
	}
	if (i < 2)
		return (0);
	return (i);
}

int find_min(int **stack, int len)
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