/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:30:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 17:26:27 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	push_swap(int ac, char **av)
{
	char	*line;
	char	**inputs;

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
	while (*inputs)
		free(*inputs++);
	free(inputs);
	return (0);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
