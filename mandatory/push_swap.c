/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:31 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/23 04:01:28 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sorted_stack(int **sorted_stack, int **stack_a, int len)
{
	int	*placeholder;
	int	i;

	i = 0;
	placeholder = malloc(sizeof(int) * len);
	while (i < len)
	{
		placeholder[i] = (*stack_a)[i];
		i++;
	}
	*sorted_stack = selection_sort(placeholder, len);
}

void	chunk_sort(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	chunk_start;
	int	chunk_end;
	int	*sorted_stack;
	int	length;

	length = *len_a;
	get_sorted_stack(&sorted_stack, stack_a, *len_a);
	chunk_start = 0;
	chunk_end = ft_sqrt(length);
	while (*len_a > 0)
	{
		if ((*stack_a)[0] <= sorted_stack[chunk_end] &&
			(*stack_a)[0] >= sorted_stack[chunk_start])
		{
			pb(stack_a, stack_b, len_a, len_b);
			pre_sort_b(stack_b, *len_b);
			if (chunk_end < length - 1)
				chunk_end++;
			if (chunk_start < length - ft_sqrt(length))
				chunk_start ++;
		}
		else if ((*stack_a)[0] < sorted_stack[chunk_start])
		{
			pb(stack_a, stack_b, len_a, len_b);
			rb(stack_b, *len_b);
			if (chunk_end < length - 1)
				chunk_end++;
			if (chunk_start < length - ft_sqrt(length))
				chunk_start ++;
		}
		else
			ra(stack_a, *len_a);
	}
	finish_sort(stack_a, stack_b, len_a, len_b);
}

void	fill_b(int **stack_b, int len)
{
	while (len-- > 0)
		(*stack_b)[len] = 0;
}

void	sort(int **stack_a, int **stack_b, int len)
{
	int	len_a;
	int	len_b;

	if (len == 1)
		return ;
	len_a = len;
	len_b = 0;
	if (len == 2)
		sort_two(stack_a, len_a, 'a');
	else if (len == 3)
		sort_three(stack_a, 'a');
	else
		chunk_sort(stack_a, stack_b, &len_a, &len_b);
}

int	has_duplicates(int **stack, int len)
{
	int	i;
	int	j;

	i = 0;
	if (stack == NULL)
		return (1);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*stack)[i] != (*stack)[j])
				j ++;
			else
				return (1);
		}
		i ++;
	}
	return (0);
}

static void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	len;

	if (ac < 2)
		error();
	stack_a = NULL;
	len = ac - 1;
	if (ac == 2)
		len = single_arg(av, &stack_a);
	else
		multiple_args(av, ac, &stack_a);
	stack_b = malloc(sizeof(int) * len);
	fill_b(&stack_b, len);
	if (is_sorted(&stack_a, len) == 1 || has_duplicates(&stack_a, len))
		error();
	else
		sort(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
