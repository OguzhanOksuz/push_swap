/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:30:02 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/18 11:42:39 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_push(int **stacks)
{
	int	mean;

	mean = (stacks[0][0] + 1) / 2;
	while (stacks[0][0] > mean)
	{
		if (stacks[0][1] <= mean)
			push(stacks[1], stacks[0], "pb\n");
		else
			rotate(stacks, "ra\n");
	}
	while (stacks[0][0] > 3)
		push(stacks[1], stacks[0], "pb\n");
	sort_little(stacks);
}

void	set_stacks(int **s)
{
	if (short_way(s[1], s[2][0]) > 0)
		while (s[1][1] != s[2][0])
			//rb;
	if (short_way(s[1], s[2][0] < 0))
		while (s[1][1] != s[2][0])
			//rrb;
	if (s[1][1] > max_val(s[0]))
	{
		if (short_way(s[0], min_val(s[0]) > 0))
			while (s[0][1] != min_val(s[0]))
				//ra;
		if (short_way(s[0], min_val(s[0]) < 0))
			while (s[0][1] != min_val(s[0]))
				//rra;
	}
	else
	{
		if (short_way(s[0], bigger_val(s[0], s[1][1])) > 0)
			while (s[0][1] != bigger_val(s[0], s[1][1]))
				//ra;
		if (short_way(s[0], bigger_val(s[0], s[1][1])) < 0)
			while (s[0][1] != bigger_val(s[0], s[1][1]))
				//rra;
	}
}

void	double_rotate(int **s)
{
	int	i;
	int	j;
	int	num;

	num = get_index(s[2], min_val(s[2]));
	if (s[1][num] > max_val(s[0]))
		i = short_way(s[0], min_val(s[0]));
	else
		i = short_way(s[0], bigger_val(s[0], s[1][num]));
	j = short_way(s[1], s[1][num]);
	while (i-- > 0 && j-- > 0)
		//rr;
	while (i++ < 0 && j++ < 0)
		//rrr;
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
}
