/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:30:02 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 23:36:48 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	first_push(int **stacks)
{
	int	mean;

	mean = (stacks[0][0]) / 2 + 1;
	while (stacks[0][0] >= mean)
	{
		if (stacks[0][1] <= mean)
			push(stacks[1], stacks[0], "pb\n");
		else if (next_way_to_mean(stacks[0], mean) > 0)
			rotate(stacks, "ra\n");
		else
			rrotate(stacks, "rra\n");
	}
	while (stacks[0][0] > 3)
		push(stacks[1], stacks[0], "pb\n");
	sort_little(stacks);
}

void	set_stacks(int **s)
{
	if (short_way(s[1], s[2][s[2][0] + 1]) > 0)
		while (s[1][1] != s[2][s[2][0] + 1])
			rotate(s, "rb\n");
	else if (short_way(s[1], s[2][s[2][0] + 1]) < 0)
		while (s[1][1] != s[2][s[2][0] + 1])
			rrotate(s, "rrb\n");
	if (s[1][1] > max_val(s[0]))
	{
		if (short_way(s[0], min_val(s[0])) > 0)
			while (s[0][1] != min_val(s[0]))
				rotate(s, "ra\n");
		else if (short_way(s[0], min_val(s[0])) < 0)
			while (s[0][1] != min_val(s[0]))
				rrotate(s, "rra\n");
	}
	else
	{
		if (short_way(s[0], bigger_val(s[0], s[1][1])) > 0)
			while (s[0][1] != bigger_val(s[0], s[1][1]))
				rotate(s, "ra\n");
		else if (short_way(s[0], bigger_val(s[0], s[1][1])) < 0)
			while (s[0][1] != bigger_val(s[0], s[1][1]))
				rrotate(s, "rra\n");
	}
}

void	double_rotate(int **s)
{
	int	i;
	int	j;
	int	num;

	num = get_index(s[1], s[2][s[2][0] + 1]);
	if (s[1][num] > max_val(s[0]))
		i = short_way(s[0], min_val(s[0]));
	else
		i = short_way(s[0], bigger_val(s[0], s[1][num]));
	j = short_way(s[1], s[1][num]);
	while (i-- > 0 && j-- > 0)
		rotate(s, "rr\n");
	while (i++ < -1 && j++ < -1)
		rrotate(s, "rrr\n");
}

void	sort_big(int **stacks)
{
	first_push(stacks);
	while (stacks[1][0] != 0)
	{		
		count_b(stacks);
		double_rotate(stacks);
		set_stacks(stacks);
		push(stacks[0], stacks[1], "pa\n");
	}
	if (short_way(stacks[0], min_val(stacks[0])) > 0)
		while (stacks[0][1] != min_val(stacks[0]))
			rotate(stacks, "ra\n");
	else if (short_way(stacks[0], min_val(stacks[0])) < 0)
		while (stacks[0][1] != min_val(stacks[0]))
			rrotate(stacks, "rra\n");
}
