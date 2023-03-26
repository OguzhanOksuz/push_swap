/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:10:38 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/26 20:02:16 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(int **stacks, int ac)
{
	int	i;

	i = 1;
	if (stacks[1][0] != 0)
		return (0);
	while (i + 1 <= stacks[0][0])
	{
		if (stacks[0][i] > stacks[0][i + 1])
			return (0);
		i++;
	}
	if (ac - 1 == stacks[0][0])
		return (1);
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	do_code(int **stacks, char *line, int code)
{
	if (code == 1)
		swap(stacks, line);
	else if (code == 2)
		rotate(stacks, line);
	else if (code == 3)
		rrotate(stacks, line);
	else if (code == 4)
		push(stacks[0], stacks[1], line);
	else if (code == 5)
		push(stacks[1], stacks[0], line);
}

void	do_rule(int **stacks, char *line)
{
	int	code;

	if (str_cmp(line, "sa\n") == 0 || str_cmp(line, "sb\n") == 0
		|| str_cmp(line, "ss\n") == 0)
		code = 1;
	else if (str_cmp(line, "ra\n") == 0 || str_cmp(line, "rb\n") == 0
		|| str_cmp(line, "rr\n") == 0)
		code = 2;
	else if (str_cmp(line, "rra\n") == 0 || str_cmp(line, "rrb\n") == 0
		|| str_cmp(line, "rrr\n") == 0)
		code = 3;
	else if (str_cmp(line, "pa\n") == 0)
		code = 4;
	else if (str_cmp(line, "pb\n") == 0)
		code = 5;
	else
	{
		code = -42;
		error();
	}
	line[0] = 0;
	do_code(stacks, line, code);
}

int	main(int ac, char **av)
{
	int		**stacks;
	char	*line;

	stacks = NULL;
	if (input_check(ac, av) == 1)
	{
		stacks = init_empty_stacks(ac);
		if (!stacks)
			error();
		stacks = init_num_stacks(ac, av, stacks);
		line = get_next_line(0);
		while (line)
		{
			do_rule(stacks, line);
			free(line);
			line = get_next_line(0);
		}
		if (is_sorted(stacks, ac))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else if (input_check(ac, av) == 0)
		error();
	return (0);
}
