/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/15 10:56:19 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>


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
//				sort_stacks(stacks);
//				TEST
				printf("max val %d\n", max_val(stacks, 0));				
				printf("min val %d\n", min_val(stacks, 0));
				printf("mean val %d\n", mean_val(stacks, 0));
				printf("Short_way_to_val %d\n", short_way_to_val(stacks, 0));

//				TEST
			}
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
