/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:29:00 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 19:00:42 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

static void	apply_moves(t_stack_data *data, char *l)
{

	if (ft_strncmp(l, "sa", 2) == 0 && ft_strlen(l) == 3)
		sa_b(data->stack_a, (*data->len_a));
	else if (ft_strncmp(l, "sb", 2) == 0 && ft_strlen(l) == 3)
		sb_b(data->stack_b, (*data->len_b));
	else if (ft_strncmp(l, "ss", 2) == 0 && ft_strlen(l) == 3)
		ss(data->stack_a, data->stack_b, (*data->len_a), (*data->len_b));
	else if (ft_strncmp(l, "pa", 2) == 0 && ft_strlen(l) == 3)
		pa_b(data->stack_a, data->stack_b, data->len_a, data->len_b);
	else if (ft_strncmp(l, "pb", 2) == 0 && ft_strlen(l) == 3)
		pb_b(data->stack_a, data->stack_b, data->len_a, data->len_b);
	else if (ft_strncmp(l, "rra", 3) == 0 && ft_strlen(l) == 4)
		rra_b(data->stack_a, (*data->len_a));
	else if (ft_strncmp(l, "rrb", 3) == 0 && ft_strlen(l) == 4)
		rrb_b(data->stack_b, (*data->len_b));
	else if (ft_strncmp(l, "rrr", 3) == 0 && ft_strlen(l) == 4)
		rrr(data->stack_a, data->stack_b, (*data->len_a), (*data->len_b));
	else if (ft_strncmp(l, "ra", 2) == 0 && ft_strlen(l) == 3)
		ra_b(data->stack_a, (*data->len_a));
	else if (ft_strncmp(l, "rb", 2) == 0 && ft_strlen(l) == 3)
		rb_b(data->stack_b, (*data->len_b));
	else if (ft_strncmp(l, "rr", 2) == 0 && ft_strlen(l) == 3)
		rr(data->stack_a, data->stack_b, (*data->len_a), (*data->len_b));
	else
		error();
}

void	check_sort(int **stack_a, int **stack_b, int len)
{
	char			*l;
	t_stack_data	data;
	int				len_a;
	int				len_b;

	len_a = len;
	len_b = 0;
	data.length = len;
	data.len_a = &len_a;
	data.len_b = &len_b;
	data.stack_a = stack_a;
	data.stack_b = stack_b;
	l = get_next_line(0);
	while (l != NULL)
	{
		apply_moves(&data, l);
        free(l);
		l = get_next_line(0);
	}
    free(l);
	if (is_sorted(stack_a, len) && len_b == 0)
		printf("OK\n");
	else
		printf("KO\n");
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
	else
		check_sort(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
