/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/14 17:21:59 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>

void	printstack(int **st)
{
	int	i;

	i = 1;
	printf("\n-----A-----\n");
	while (i <= st[0][0])
	{
		printf("%d\n", st[0][i]);
		i++;
	}
	i = 1;
	printf("\n-----B-----\n");
	while (i <= st[1][0])
	{
		printf("%d\n", st[1][i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	**stacks;

	stacks = NULL;
	if (input_num_check(ac, av) && input_dup_check(ac, av))
	{
		if (input_num_range_check(ac, av))
		{
			stacks = init_empty_stacks(ac);
			if (stacks)
			{
				stacks = init_num_stacks(ac, av, stacks);
				stacks = init_index_stacks(stacks);
				// TESSTTT
				int lop = 2;
				while (lop-- > 0)
				{
					printstack(stacks);
					push(stacks[1], stacks[0], "pb\n");
					push(stacks[1], stacks[0], "pb\n");
					push(stacks[1], stacks[0], "pb\n");
					printstack(stacks);
					push(stacks[0], stacks[1], "pa\n");
					printstack(stacks);
					rotate(stacks, "ra\n");
					rotate(stacks, "rb\n");
					printstack(stacks);
					rrotate(stacks, "rra\n");
					rrotate(stacks, "rrb\n");
					printstack(stacks);
					swap(stacks, "sa\n");
					swap(stacks, "sb\n");
					swap(stacks, "sb\n");
				}
						
				// TESTTT
			}
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
