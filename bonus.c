/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:44:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 20:21:56 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	is_sorted(int **stacks)
{
	int	i;

	if (stacks[1][0] != 0)
		return (0);
	i = 0;
	if (stacks[0][0] > 0)
		while (++i + 1 <= stacks[0][0])
			if (stacks[0][i + 1] < stacks[0][i])
				return (0);
	return (1);
}

int	do_prompt(int **stacks, char *p)
{
	int	rule_code;

	rule_code = 0;
	if (!scmp(p, "sa\n") || !scmp(p, "sb\n") || !scmp(p, "ss\n"))
		rule_code = 1;
	else if (!scmp(p, "ra\n") || !scmp(p, "rb\n") || !scmp(p, "rr\n"))
		rule_code = 2;
	else if (!scmp(p, "rra\n") || !scmp(p, "rrb\n") || !scmp(p, "rrr\n"))
		rule_code = 3;
	else if (!scmp(p, "pa\n"))
		rule_code = 4;
	else if (!scmp(p, "pb\n"))
		rule_code = 5;
	p[0] = 0;
	if (rule_code == 1)
		swap(stacks, p);
	else if (rule_code == 2)
		rotate(stacks, p);
	else if (rule_code == 3)
		rrotate(stacks, p);
	else if (rule_code == 4)
		push(stacks[0], stacks[1], p);
	else if (rule_code == 5)
		push(stacks[1], stacks[0], p);
	return (rule_code);
}

int	checker(int **stacks)
{
	char	*promt;
	int		valid;

	promt = get_next_line(0);
	if (is_sorted(stacks) && promt)
		write (1, "KO\n", 3);
	else
	{
		valid = 1;
		while (promt && valid != 0)
		{
			valid = do_prompt(stacks, promt);
			free(promt);
			promt = get_next_line(0);
		}
		if (is_sorted(stacks))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	if (promt)
		free(promt);
	free(stacks[0]);
	return (free(stacks[1]), free(stacks[2]), free(stacks), 0);
}

int	main(int ac, char **av)
{
	char	*line;
	char	**inputs;
	int		i;

	if (ac != 1)
	{
		line = input_join(ac, av);
		if (!line)
			return (write(2, "Error\n", 6));
		inputs = ft_split(line, ' ');
		free(line);
		if (!inputs)
			return (write(2, "Error\n", 6));
		if (input_check(inputs) == 1)
			checker(init_stacks(inputs));
		else
			write(2, "Error\n", 6);
		i = 0;
		while (inputs[i])
			free(inputs[i++]);
		free(inputs[i]);
		free(inputs);
	}
	return (0);
}
