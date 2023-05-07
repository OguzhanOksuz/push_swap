/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:32:10 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/07 16:46:20 by ooksuz           ###   ########.fr       */
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
