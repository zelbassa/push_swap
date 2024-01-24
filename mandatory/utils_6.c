/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:56:05 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/24 15:35:54 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_up(int **stack_b, int *len_b, int index)
{
	int	i;

	i = 0;
	if (index == 0)
		return ;
	while (i < index)
	{
		rb(stack_b, *len_b);
		i ++;
	}
}

void	push_down(int **stack_b, int *len_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rrb(stack_b, *len_b);
		i ++;
	}
}

void	fill_b(int **stack_b, int len)
{
	while (len-- > 0)
		(*stack_b)[len] = 0;
}

void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

int	ind_min(int **stack, int len)
{
	int	i;
	int	k;
	int	min_value;

	i = 0;
	k = 1;
	min_value = 0;
	while (i < len - 1 && k + i < len)
	{
		if ((*stack)[i] < (*stack)[i + k])
			k ++;
		else
		{
			i = k;
			k ++;
		}
		min_value = i;
	}
	return (min_value);
}
