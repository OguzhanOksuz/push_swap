/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/17 18:45:39 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *stack, int num)
{
	int	i;

	i = 1;
	while (i <= stack[0])
	{
		if (stack[i] == num)
			break ;
		i++;
	}
	return (i);
}

int	step_to_set(int *stack, int num)
{
	int	i;

	i = 1;
	while (i <= stack[0] && i != num)
		i++;
	if (i <= stack[0] / 2)
		return (i);
	else
		return (stack[0] - i);
}

int	worth_b(int **stacks)
{
	int	i;

	i = 1;
	stacks[2][0] = stacks[1][0];
	while (i <= (stacks[1][0] + 1) / 2)
	{
		stacks[2][i] = worth_a(stacks, i) + i;
		i++;
	}
	while (i <= stacks[1][0])
	{
		stacks[2][i] = worth_a(stacks, i) + stacks[2][0] - i;
		i++;
	}
	i = 1;
	while (stacks[2][i] != min_val(stacks[2]))
			i++;
	if (i <= (stacks[1][0] + 1) / 2)
		return (i + stacks[2][i]);
	return (stacks[2][i] + stacks[1][0] - i);
}

int	worth_a(int **s, int num)
{
	int	big;
	int	min;
	int	i;

	i = 1;
	big = bigger_val(s[0], s[1][num]);
	min = min_val(s[0]);
	if (s[1][num] < max_val(s[0]))
	{
		if (short_val(s[0], big) >= 0)
			while (s[0][i] != big)
				i++;
	}
	else
		while (s[0][i] != min)
			i++;
	if (i < (s[0][0] + 1) / 2)
		return (i);
	return (s[0][0] - i);
}
