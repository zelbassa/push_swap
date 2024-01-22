/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:57 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 15:57:48 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_tokens(int **tokens, int **av)
{
	int	i;

	i = 0;
	if (tokens)
	{
		while (tokens[i])
		{
			if (is_int(tokens[i]) && within_range(tokens[i]))
				i++;
			else
				return (0);
		}
	}
	if (i < 2)
		return (0);
	return (i);
}

int	single_arg(char **av, int **stack)
{
	int		i;
	char	**tokens;

	i = set_tokens(tokens, av);
	*stack = malloc(sizeof(int) * i);
	if (*stack == NULL)
		return (0);
	i = 0;
	while (tokens[i])
	{
		(*stack)[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (i);
}

int	multiple_args(char **av, int ac, int **stack)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	*stack = malloc(sizeof(int) * (ac - 1));
	if (*stack == NULL)
		return ;
	while (j < ac)
	{
		if (is_int(av[j]) && within_range(av[j]))
		{
			(*stack)[i] = ft_atoi(av[j]);
			i++;
		}
		else
		{
			free_stack(stack);
			return ;
		}
		j++;
	}
}
