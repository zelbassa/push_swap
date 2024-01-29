/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:31 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/27 16:12:35 by zelbassa         ###   ########.fr       */
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

void	chunk_sort_iteration(t_chunk_sort_data *data)
{
	if (data->stack_a[0][0] <= data->sorted_stack[data->chunk_end] &&
		data->stack_a[0][0] >= data->sorted_stack[data->chunk_start])
	{
		pb(data->stack_a, data->stack_b, data->len_a, data->len_b);
		pre_sort_b(data->stack_b, *(data->len_b));
		if (data->chunk_end < data->length - 1)
			data->chunk_end++;
		if (data->chunk_start < data->length - ft_sqrt(data->length) / 2)
			data->chunk_start++;
	}
	else if (data->stack_a[0][0] < data->sorted_stack[data->chunk_start])
	{
		pb(data->stack_a, data->stack_b, data->len_a, data->len_b);
		rb(data->stack_b, *(data->len_b));
		if (data->chunk_end < data->length - 1)
			data->chunk_end++;
		if (data->chunk_start < data->length - ft_sqrt(data->length) / 2)
			data->chunk_start++;
	}
	else
		ra(data->stack_a, *(data->len_a));
}

void	chunk_sort(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int					chunk_start;
	int					chunk_end;
	int					*sorted_stack;
	int					length;
	t_chunk_sort_data	data;

	chunk_start = 0;
	length = *len_a;
	get_sorted_stack(&sorted_stack, stack_a, *len_a);
	chunk_end = ft_sqrt(length);
	data.stack_a = stack_a;
	data.stack_b = stack_b;
	data.len_a = len_a;
	data.len_b = len_b;
	data.sorted_stack = sorted_stack;
	data.chunk_start = chunk_start;
	data.chunk_end = chunk_end;
	data.length = length;
	while (*(data.len_a) > 0)
		chunk_sort_iteration(&data);
	finish_sort(stack_a, stack_b, len_a, len_b);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	len;

	if (ac == 1)
		return (0);
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
	if (has_duplicates(&stack_a, len))
		error();
	if (is_sorted(&stack_a, len) == 1)
		return (0);
	else
		sort(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
