/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:57 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/24 16:13:28 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (ft_strchr(str, ' ') || ft_strchr(str, '\t'))
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

/*
void multiple_args(char **av, int ac, int **stack) {
    int i = 0;
    int total_elements = 0;

    // Count total elements across all arguments
    for (int j = 1; j < ac; j++) {
        total_elements += count_words(av[j]);
    }

    *stack = malloc(sizeof(int) * total_elements);
    if (*stack == NULL) {
        return;  // Handle memory allocation error
    }

    // Fill the stack with elements from each argument
    for (int j = 1; j < ac; j++) {
        char *arg = av[j];
        char *token = strtok(arg, " ");  // Split argument by spaces
        while (token != NULL) {
            (*stack)[i++] = atoi(token);  // Convert token to integer and add to stack
            token = strtok(NULL, " ");
        }
    }
} */

void	multiple_args(char **av, int ac, int **stack)
{
	int	i;
	int	j;
	int	len;
	char **tokens;

	j = 1;
	i = 0;
	while (j < ac)
	{
		len = count_words(av[j]);
		j++;
	}
	j = 1;
	*stack = malloc(sizeof(int) * len);
	if (*stack == NULL)
		return ;
	while (j < ac)
	{
		tokens = ft_split(av[j], ' ');
		while (tokens[i] != NULL)
		{
			if (is_int(tokens[i]) && within_range(tokens[i]))
			{
				(*stack)[i] = ft_atoi(tokens[i]);
				i++;
			}
			else
			{
				free_stack(stack);
				error();
			}
		}
		j ++;
	}
}

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
		if (is_int(tokens[i]) && within_range(tokens[i]))
		{
			(*stack)[i] = ft_atoi(tokens[i]);
			i++;
		}
		else
		{
			free_stack(stack);
			return (0);
		}
	}
	return (i);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
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
