/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:40:22 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 18:34:02 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 5

typedef struct s_stack_data
{
	int	**stack_a;
	int	**stack_b;
	int	*len_a;
	int	*len_b;
	int	length;
}		t_stack_data;

void	error(void);
void	sa_b(int **stack_a, int len_a);
void	sb_b(int **stack_b, int len_b);
void	ra_b(int **stack_a, int len_a);
void	rb_b(int **stack_b, int len_b);
void	rra_b(int **stack_a, int len_a);
void	rrb_b(int **stack_b, int len_b);
void	pb_b(int **src, int **dest, int *len_src, int *len_dest);
void	pa_b(int **dest, int **src, int *len_src, int *len_dest);
void	rrr(int **stack_al, int **stack_b, int len_a, int len_b);
void	ss(int **stack_a, int **stack_b, int len_a, int len_b);
void	rr(int **stack_a, int **stack_b, int len_a, int len_b);
void	multiple_args(char **av, int ac, int **stack);
int		single_arg(char **av, int **stack);
int		set_tokens(char **tokens);
int		is_sorted(int **stack, int *len_a, int *len_b);
int		is_int(char *str);
int		within_range(const char *str);
void	free_stack(int **stack);
int		has_duplicates(int **stack, int len);
void	fill_b(int **stack_b, int len);
void	fill_elements(char *av, int **stack, int *i);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif