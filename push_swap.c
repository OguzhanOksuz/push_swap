/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/14 13:15:47 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>


int	main(int ac, char **av)
{
	int	**stacks;

	stacks = NULL;
	if (1)//input_num_check(ac, av) && input_dup_check(ac, av))
	{
		if (1)//input_num_range_check(ac, av))
		{
//			stacks = init_empty_stacks(ac);
			if (1)//stacks)
			{
//(				stacks = init_num_stacks(ac, av, stacks);
//				stacks = init_index_stacks(stacks);
				// TESSTTT
//					printf ("\n---A---\n");
//					printf ("%d\n%d\n%d\n%d\n", stacks[0][1], stacks[0][2], stacks[0][3], stacks[0][4]);
//					swap(stacks, "sa\n");
						


				// TESTTT
			}
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	printf("%s", av[ac - 1]);
}
