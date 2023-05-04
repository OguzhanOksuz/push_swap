/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 20:35:18 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	is_sorted(int *stack)
{
	int	i;

	i = 1;
	while (i + 1 <= stack[0])
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_little(int **stacks)
{
	if (stacks[0][1] == max_val(stacks[0]))
		rotate(stacks, "ra\n");
	else if (stacks[0][2] == max_val(stacks[0]))
		rrotate(stacks, "rra\n");
	if (stacks[0][1] > stacks[0][2] && stacks[0][0])
		swap(stacks, "sa\n");
}

void	sort_middle(int **stacks)
{
	while (stacks[0][0] > 3)
	{
		if (short_way(stacks[0], min_val(stacks[0])) > 0)
			while (stacks[0][1] != min_val(stacks[0]))
				rotate(stacks, "ra\n");
		else if (short_way(stacks[0], min_val(stacks[0])) < 0)
			while (stacks[0][1] != min_val(stacks[0]))
				rrotate(stacks, "rra\n");
		push(stacks[1], stacks[0], "pb\n");
	}
	sort_little(stacks);
	if (stacks[1][0] == 2 && stacks[1][1] < stacks[1][2])
		rotate(stacks, "ra\n");
	while (stacks[1][0] != 0)
		push(stacks[0], stacks[1], "pa\n");
}

void	sort_all(int **stacks)
{
	if (stacks[0][0] == 2)
	{
		if (stacks[0][1] > stacks[0][2])
			rotate(stacks, "ra\n");
	}
	else if (stacks[0][0] == 3)
	{
		sort_little(stacks);
	}
	else if (stacks[0][0] == 5)
	{
		sort_middle(stacks);
	}
	else
	{
		sort_big(stacks);
	}
}
