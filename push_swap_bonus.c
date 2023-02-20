/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:20 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/02/20 20:51:25 by Ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

int	is_sorted(int *stack)
{
	int	i;

	i = 1;
	while (i + 1 <= stack[0])
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	scmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

void	checker(int **stacks)
{
	char	*l;

	l = get_next_line(0);
	while (l)
	{
		if (scmp(l, "rra\n") || scmp(l, "rrb\n") || scmp(l, "rrr\n"))
			checker_rrotate(stacks, l);
		else if (scmp(l, "ra\n") || scmp(l, "rb\n") || scmp(l, "rr\n"))
			checker_rotate(stacks, l);
		else if (scmp(l, "pa\n"))
			checker_push(stacks[0], stacks[1]);
		else if (scmp(l, "pb\n"))
			checker_push(stacks[1], stacks[0]);
		else if (scmp(l, "sa\n") || scmp(l, "sb\n"))
			checker_swap(stacks, l);
		else
			write(2, "Error\n", 6);
		l = get_next_line(0);
	}
	if (is_sorted(stacks[0]) && stacks[1][0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int	**stacks;

	stacks = NULL;
	if (input_check(ac, av) == 1)
	{
		stacks = init_empty_stacks(ac);
		if (stacks)
		{
			stacks = init_num_stacks(ac, av, stacks);
			checker(stacks);
			free(stacks[0]);
			free(stacks[1]);
			free(stacks[2]);
			free(stacks);
		}
		else
			write(2, "Error\n", 6);
	}
	else if (input_check(ac, av) == 0)
		write(2, "Error\n", 6);
	return (0);
}
