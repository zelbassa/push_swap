/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:03:58 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 18:54:02 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
    free_tokens(tokens);
}

void	fill_b(int **stack_b, int len)
{
	while (len-- > 0)
		(*stack_b)[len] = 0;
}

void	pb_b(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	placeholder;

	i = 0;
	if (*len_a == 0)
		return ;
	placeholder = (*stack_a)[0];
	while (i < (*len_a) - 1)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	j = *len_b;
	while (j > 0)
	{
		(*stack_b)[j] = (*stack_b)[j - 1];
		j--;
	}
	(*stack_a)[*len_a - 1] = 0;
	(*len_a)--;
	(*len_b)++;
	(*stack_b)[0] = placeholder;
}

void	pa_b(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	i;
	int	j;
	int	placeholder;

	i = 0;
	if (*len_b == 0)
		return ;
	placeholder = (*stack_b)[0];
	while (i < (*len_b) - 1)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	j = *len_a;
	while (j > 0)
	{
		(*stack_a)[j] = (*stack_a)[j - 1];
		j--;
	}
	(*stack_b)[*len_b - 1] = 0;
	(*len_b)--;
	(*len_a)++;
	(*stack_a)[0] = placeholder;
}

void	sa_b(int **stack_a, int len_a)
{
	int	tmp;

	if (len_a < 2)
		return ;
	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
}
