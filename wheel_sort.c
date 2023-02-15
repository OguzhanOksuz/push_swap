/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:01:06 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/15 14:48:49 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stack(int *stack)
{
	int	i = 1;
	while (i <= stack[0])
	{		
		printf("%d = %d\n", i, stack[i]);
		i++;
	}
}

void	sort_3_elem(int **stacks)
{
	if (stacks[1][0] == 2 && (stacks[1][1] < stacks[1][2]))
		swap(stacks, "sb\n");
	else if (stacks[1][0] == 3 && (stacks[1][1] < stacks[1][2]))
	{
		swap(stacks, "sb\n");
		if (stacks[1][2] < stacks[1][3])
		{
			rotate(stacks, "rb\n");
			swap(stacks, "sb\n");
			rrotate(stacks, "rrb\n");
		}
	}
}

int	next_max_of_less_val(int *stack, int grana)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 1;
	while (i <= stack[0])
	{
		if (tmp < stack[i] && stack[i] < grana)
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	short_way_to_rotate(int *stack, int num)
{
	int	i;
	int	j;

	i = 1;
	j = stack[0];
	if (num == 0)
		return (0);
	while (i <= stack[0] && stack[i] != num)
		i++;
	while (j >= 1 && stack[j] != num)
		j--;
	if (i > stack[0] && j < 1)
		return (0);
	if (i < j)
		return (1);
	else
		return (-1);
}

void	set_wheel_pos(int **stacks, int grana)
{
	int	next_val;

	if (stacks[1][0] > 3)
	{
		next_val = next_max_of_less_val(stacks[1], grana);
		if (short_way_to_rotate(stacks[1], next_val) > 0)
			while (stacks[1][1] != next_val)
				rotate(stacks, "rb\n");
		else if (short_way_to_rotate(stacks[1], next_val) < 0)
			while (stacks[1][1] != next_val)
				rrotate(stacks, "rrb\n");
	}
	else
		sort_3_elem(stacks);
}



void	wheel_sort(int **stacks)
{
	int	mean;

	while (stacks[0][0] >= 5)
	{	
		mean = mean_val(stacks[0]);
		while (short_way_to_val(stacks[0], mean))
		{
			if (short_way_to_val(stacks[0], mean) > 0)
				while (stacks[0][1] < mean)
					rotate(stacks, "ra\n");
			else if (short_way_to_val(stacks[0], mean) < 0)
				while (stacks[0][1] <= mean)
					rrotate(stacks, "rra\n");
			set_wheel_pos(stacks, stacks[0][1]);
			push(stacks[1], stacks[0], "pb\n");
		}
			printf("\nA\n");
			print_stack(stacks[0]);

			printf("\nB\n");
			print_stack(stacks[1]);
	}
}
