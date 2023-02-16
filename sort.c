/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:30:02 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/16 19:29:06 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_push(int **stacks)
{
	int	mean;

	mean = stacks[0][0] / 2;
	while (stacks[0][0] > mean)
	{
		if (stacks[0][1] <= mean)
		{
			push(stacks[1], stacks[0], "pb\n");
			continue ;
		}
		if (short_way_to_mean_val(stacks[0], mean) >= 1)
			rotate(stacks, "ra\n");
		else if (short_way_to_mean_val(stacks[0], mean) <= -1)
			rrotate(stacks, "rra\n");	
	}
	while (stacks[0][0] > 3)
		push(stacks[1], stacks[0], "pb\n");
}

void	aline_stacks(int **stacks)
{
	while (
}

void	sort_little(int **stacks)
{

}

void	sort_big(int **stacks)
{
	first_push(stacks);
	sort_little(stacks);
	while (stacks[1][0] != 0)
	{
		if (step_counts_for_rot_a(stacks, 1) <= step_counts_for_rot_b(stacks))
			rotate_a(stacks);
		else
			rotate_b(stacks);
		push(stacks[0], stacks[1], "pa\n");
	}
}
