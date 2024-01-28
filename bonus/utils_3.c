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
}

void	fill_b(int **stack_b, int len)
{
	while (len-- > 0)
		(*stack_b)[len] = 0;
}

void	pb_b(int **src, int **dest, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	i = 0;
	j = 0;
	if (*len_src == 0)
		return ;
	placeholder = (*src)[0];
	while (i < (*len_src) - 1)
	{
		(*src)[i] = (*src)[i + 1];
		i++;
	}
	j = *len_dest;
	i = 0;
	while (j > 0)
	{
		(*dest)[j] = (*dest)[j - 1];
		j--;
	}
	(*src)[*len_src - 1] = 0;
	(*len_src)--;
	(*len_dest)++;
	(*dest)[0] = placeholder;
}

void	pa_b(int **dest, int **src, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	j = 0;
	i = 0;
	if (*len_src == 0)
		return ;
	placeholder = (*src)[0];
	while (i < (*len_src) - 1)
	{
		(*src)[i] = (*src)[i + 1];
		i++;
	}
	i = 0;
	j = *len_dest;
	while (j > 0)
	{
		(*dest)[j] = (*dest)[j - 1];
		j--;
	}
	(*src)[*len_src - 1] = 0;
	(*len_src)--;
	(*len_dest)++;
	(*dest)[0] = placeholder;
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
