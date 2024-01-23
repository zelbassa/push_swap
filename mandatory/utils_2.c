/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:24:31 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/23 03:58:09 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int **src, int **dest, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	i = 0;
	j = 0;
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
	ft_putstr("pb\n");
}

void	pa(int **dest, int **src, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	j = 0;
	i = 0;
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
