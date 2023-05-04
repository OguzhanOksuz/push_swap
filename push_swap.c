/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:30:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 18:59:06 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	do_sort(char **inputs)
{
	int	**stacks;

	stacks = init_stacks(inputs);
	if (!inputs)
		return (write(2, "Error\n", 6));
	return (0);
}

int	push_swap(int ac, char **av)
{
	char	*line;
	char	**inputs;
	int	i;

	line = input_join(ac, av);
	if (!line)
		return (write(2, "Error\n", 6));
	inputs = ft_split(line, ' ');
	free(line);
	if (!inputs)
		return (write(2, "Error\n", 6));
	if (input_check(inputs) == 1)
		do_sort(inputs);
	else
		write(2, "Error\n", 6);
	i = 0;
	while (inputs[i])
		free(inputs[i++]);
	free(inputs[i]);
	free(inputs);
	return (0);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
