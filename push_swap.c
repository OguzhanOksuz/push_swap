/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/01 16:03:21 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_free(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list[i]);
	free(list);
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int		**stacks;

	stacks = NULL;
	av = input_format(ac, av);
	if (!av)
		return (write(2, "Error\n", 6) - 6);
	ac = get_new_ac(av);
	if (input_check(ac, av) == 1)
	{
		stacks = init_empty_stacks(ac);
		if (stacks)
		{
			stacks = init_num_stacks(ac, av, stacks);
			sort_all(stacks);
		}
		else
			my_free(av);
	}
	else if (input_check(ac, av) == 0)
		my_free(av);
	return (0);
}
