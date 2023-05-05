/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:44:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 22:52:05 by ooksuz           ###   ########.fr       */
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

char	**get_prompt(void)
{
	char	*rd;
	char	*line;
	char	**prompt;
	int		flag;

	line = NULL;
	rd = (char *)malloc(sizeof(char) * 2);
	if (!rd)
		return (NULL);
	flag = read(0, rd, 1);
	rd[flag] = 0;
	while (rd[0] && flag > 0)
	{
		line = ft_strjoin(line, rd);
		flag = read(0, rd, 1);
		if (flag < 0)
			return (free(rd), free(line), NULL);
		rd[flag] = 0;
	}
	free (rd);
	prompt = ft_split(line, '\n');
	free(line);
	return (prompt);
}

int	do_prompt(int **stacks, char *p)
{
	int	rule_code;

	rule_code = 0;
	if (!scmp(p, "sa") || !scmp(p, "sb") || !scmp(p, "ss"))
		rule_code = 1;
	else if (!scmp(p, "ra") || !scmp(p, "rb") || !scmp(p, "rr"))
		rule_code = 2;
	else if (!scmp(p, "rra") || !scmp(p, "rrb") || !scmp(p, "rrr"))
		rule_code = 3;
	else if (!scmp(p, "pa"))
		rule_code = 4;
	else if (!scmp(p, "pb"))
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

int	checker(int **stacks, char **prompt)
{
	int		valid;
	int		i;

	i = 0;
	while (prompt[i])
	{
		valid = do_prompt(stacks, prompt[i++]);
		if (!valid)
		{
			write(1, "KO\n", 3);
			break ;
		}
	}
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else if (valid)
		write(1, "KO\n", 3);
	i = -1;
	while (prompt[++i])
		free(prompt[i]);
	free(prompt);
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
			checker(init_stacks(inputs), get_prompt());
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
