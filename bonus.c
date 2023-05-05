/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:44:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 13:11:33 by ooksuz           ###   ########.fr       */
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
		while (++i + 1 < stacks[0][0])
			if (stacks[0][i + 1] < stacks[0][i])
				return (0);
	return (1);
}

int	sc(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	do_prompt(int **stacks, char *p)
{
	int	rule_code;

	rule_code = 0;
	if (!sc(p, "sa\n") || !sc(p, "sb\n") || !sc(p, "ss\n"))
		rule_code = 1;
	else if (!sc(p, "ra\n") || !sc(p, "rb\n") || !sc(p, "rr\n"))
		rule_code = 2;
	else if (!sc(p, "rra\n") || !sc(p, "rrb\n") || !sc(p, "rrr\n"))
		rule_code = 3;
	else if (!sc(p, "pa\n"))
		rule_code = 4;
	else if (!sc(p, "pb\n"))
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
	return (free(p), rule_code);
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
		while (promt && valid)
		{
			valid = do_prompt(stacks, promt);
			promt = get_next_line(0);
		}
		if (is_sorted(stacks) && promt)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free (stacks[0]);
	free (stacks[1]);
	free (stacks[2]);
	free (stacks);
	return (0);
}

int	main(int ac, char **av)
{
	char	*line;
	char	**inputs;
	int		i;

	line = input_join(ac, av);
	if (!line)
		return (write(2, "error\n", 6));
	inputs = ft_split(line, ' ');
	free(line);
	if (!inputs)
		return (write(2, "error\n", 6));
	if (input_check(inputs) == 1)
		checker(init_stacks(inputs));
	else
		write(2, "error\n", 6);
	i = 0;
	while (inputs[i])
		free(inputs[i]);
	free(inputs[i]);
	free(inputs);
	return (0);
}
