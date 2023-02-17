/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:30:02 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/17 19:55:00 by ooksuz           ###   ########.fr       */
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

void	double_rot(int **stacks)
{
	int	i;

	i = rot_val(stacks);
	printf("i = %d\n", i);
	while (i > 0)
	{
		double_rotate(stacks, "rr\n");
		i--;
	}
	while (i < 0)
	{
		double_rrotate(stacks, "rrr\n");
		i++;
	}
}

void	rotate_a(int **s)
{
	int	big;
	int	min;

	min = min_val(s[0]);
	big = bigger_val(s[0], s[1][1]);
	if (s[1][1] < max_val(s[0]))
	{
		if (short_val(s[0], big) >= 0)
			while (s[0][1] != big)
				rotate(s, "ra\n");
		else
			while (s[0][1] != big)
			{	
				rrotate(s, "rra\n");
				printf("debug\n");
			}
	}
	else
		while (s[0][1] != min)
			rotate(s, "ra\n");
}

void	rotate_b(int **stacks)
{
	int	min;

	min = stacks[1][get_index(stacks[2], min_val(stacks[2]))];
	double_rot(stacks);
	if (short_val(stacks[1], min) >= 0)
	{
		while (stacks[1][1] != min)
			rotate(stacks, "rb\n");
	}
	else
		while (stacks[1][1] != min)
		{
			rrotate(stacks, "rrb\n");
		}
	rotate_a(stacks);
}

void	sort_big(int **stacks)
{
	first_push(stacks);
	while (stacks[1][0] != 0)
	{
	//	if (worth_b(stacks) > worth_a(stacks, 1))
	//			rotate_a(stacks);
		//else
			rotate_b(stacks);
		push(stacks[0], stacks[1], "pa\n");
	}
}
