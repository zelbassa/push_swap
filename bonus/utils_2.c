/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:57:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 19:01:09 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(int **stack, int len)
{
	int	i;

	i = 1;
	while (i < len - 1)
	{
		if ((*stack)[i - 1] > (*stack)[i])
			return (0);
		i ++;
	}
	return (1);
}

void	free_stack(int **stack)
{
	free(*stack);
	*stack = NULL;
}

static int	count_element(char *av)
{
	int		i;
	char	**tokens;

	i = 0;
	tokens = ft_split(av, ' ');
	while (tokens[i])
		i++;
    free_tokens(tokens);
	return (i);
}

void	multiple_args(char **av, int ac, int **stack)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 1;
	i = 0;
	while (j < ac)
	{
		len += count_element(av[j]);
		j++;
	}
	if (len != ac - 1)
		error();
	j = 1;
	*stack = malloc(sizeof(int) * ac - 1);
	if (*stack == NULL)
		return ;
	while (j < ac)
	{
		fill_elements(av[j], stack, &i);
		j++;
	}
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
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
