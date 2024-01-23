/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:56:05 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/23 04:20:47 by zelbassa         ###   ########.fr       */
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

void	show_stack(int **stack_a, int **stack_b, int length)
{
	if (stack_a)
	{
		for (int i = 0; i < length; i++)
			printf("Stack_a[%d]: %d\n", i, (*stack_a)[i]);
	}
	if (stack_b)
	{
		printf("-------------\n");
		for (int i = 0; i < length; i++)
			printf("Stack_b[%d]: %d\n", i, (*stack_b)[i]);
	}
}
