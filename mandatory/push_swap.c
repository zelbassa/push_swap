/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:31 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:28:41 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sorted_stack(int **sorted_stack, int **stack_a, int len)
{
	int *placeholder;
	int i;

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
	while (*len_a > 3)
	{
		if ((*stack_a)[0] <= sorted_stack[chunk_end] &&
			(*stack_a)[0] >= sorted_stack[chunk_start])
		{
			pb(stack_a, stack_b, len_a, len_b);
			pre_sort_b(stack_b, *len_b);
			if (chunk_end < length - 1)
				chunk_end++;
			chunk_start ++;
		}
		else if ((*stack_a)[0] < sorted_stack[chunk_start])
		{
			pb(stack_a, stack_b, len_a, len_b);
			rb(stack_b, *len_b);
			if (chunk_end < length - 1)
				chunk_end++;
			chunk_start ++;
		}
		else
			ra(stack_a, *len_a);
	}
	finish_sort(stack_a, stack_b, len_a, len_b);
}

void	sort(int **stack_a, int **stack_b, int len)
{
	int	len_a;
	int	len_b;

	len_a = len;
	len_b = 0;
	if (len == 2)
		sort_two(stack_a, len_a, 'a');
	else if (len == 3)
		sort_three(stack_a, 'a');
	else
		chunk_sort(stack_a, stack_b, &len_a, &len_b);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	len;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	len = ac - 1;
	if (ac == 2)
		len = single_arg(av, &stack_a);
	else
		len = multiple_args(av, ac, &stack_a);
	if (is_sorted(&stack_a, len) == 1)
		return (0);
	else
		sort(&stack_a, &stack_b, len);
	free(stack_a);
	free(stack_b);
	return (0);
}
