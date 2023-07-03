/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:32:10 by ooksuz            #+#    #+#             */
/*   Updated: 2023/07/03 22:49:52 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	my_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	check_prompt(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			j++;
		else
		{
			if (j < 2 || j >= 5)
				return (0);
			j = 0;
		}
		i++;
	}
	if (i != 0)
		if (line[i - 1] != '\n')
			return (0);
	return (1);
}

char	**get_prompt(void)
{
	char	*rd;
	char	*line;
	char	**prompt;
	int		flag;

	prompt = NULL;
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
	if (check_prompt(line) == 1)
		prompt = ft_split(line, '\n');
	free(line);
	return (prompt);
}

int	init_checker(int ac, char **av)
{
	char	*line;
	char	**input;
	char	**prompt;

	if (ac != 1)
	{
		line = input_join(ac, av);
		if (!line)
			return (write(2, "Error\n", 6));
		input = ft_split(line, ' ');
		free (line);
		if (!input)
			return (write(2, "Error\n", 6));
		if (input_check(input) == 0)
			return (my_free(input), write(2, "Error\n", 6));
		prompt = get_prompt();
		checker(init_stacks(input), prompt);
		my_free(input);
		my_free(prompt);
	}
	return (0);
}

int	main(int ac, char **av)
{
	init_checker(ac, av);
	return (0);
}
