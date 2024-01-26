/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:57 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/24 20:30:10 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_arg(char **av, int **stack)
{
	int		i;
	char	**tokens;

	tokens = ft_split(av[1], ' ');
	i = set_tokens(tokens);
	if (i == 0)
		return (0);
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

static int	count_element(char *av)
{
	int		i;
	char	**tokens;

	i = 0;
	tokens = ft_split(av, ' ');
	while (tokens[i])
		i++;
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
	if (len > ac - 1)
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

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i ++;
	}
	return (i - 1);
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
