/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:56:05 by prizmo            #+#    #+#             */
/*   Updated: 2024/01/22 18:27:37 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_up(int **stack_b, int *len_b, int index)
{
	int	i = 0;

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
	int	i = 0;

	while (i < index)
	{
		rrb(stack_b, *len_b);
		i ++;
	}
}