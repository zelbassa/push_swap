/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:54:58 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/27 23:01:17 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	single_arg(char **av, int **stack)
{
	int		i;
	char	**tokens;

	tokens = ft_split(av[1], ' ');
	i = set_tokens(tokens);
	if (i == 0)
	{
		free_tokens(tokens);
		exit(0);
	}
	*stack = malloc(sizeof(int) * i);
	if (*stack == NULL)
		return (0);
	i = 0;
	while (tokens[i])
	{
		(*stack)[i] = ft_atoi(tokens[i]);
		i++;
	}
    free_tokens(tokens);
	return (i);
}

int	set_tokens(char **tokens)
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
				error();
		}
	}
	if (i < 2)
		return (0);
	return (i);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (i > 10)
			return (0);
		i++;
	}
	return (1);
}

int	within_range(const char *str)
{
	const char	*max;
	const char	*min;

	max = "2147483647";
	min = "-2147483648";
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 10 && ft_strcmp(str, max) > 0)
		return (0);
	if (ft_strlen(str) == 11 && ft_strcmp(str, min) > 0)
		return (0);
	return (1);
}
