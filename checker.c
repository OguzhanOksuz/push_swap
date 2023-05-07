/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:44:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/07 17:41:31 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	free_stacks(int **stacks)
{
	if (!stacks)
		return ;
	free(stacks[0]);
	free(stacks[1]);
	free(stacks[2]);
	free(stacks);
}

int	is_stacks_sorted(int **stacks)
{
	int	i;

	if (stacks[1][0] != 0)
		return (0);
	i = 1;
	while (i + 1 <= stacks[0][0])
	{
		if (stacks[0][i] > stacks[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	**get_prompt(void)
{
	char	*rd;
	char	*line;
	char	**prompt;
	int		flag;

	flag = 1;
	line = NULL;
	rd = (char *)malloc(sizeof(char) * 2);
	if (!rd)
		return (NULL);
	while (flag > 0)
	{
		flag = read(0, rd, 1);
		if (flag < 0)
			return (free(rd), free(line), NULL);
		rd[flag] = 0;
		line = ft_strjoin(line, rd);
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

void	checker(int **stacks, char **prompt)
{
	int	i;
	int	valid;

	valid = 1;
	i = 0;
	if (stacks)
	{
		if (prompt)
			while (prompt[i] && valid)
				valid = do_prompt(stacks, prompt[i++]);
		if (valid == 0 || is_stacks_sorted(stacks) == 0)
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
		free_stacks(stacks);
	}
	else
		write(2, "Error\n", 6);
}
