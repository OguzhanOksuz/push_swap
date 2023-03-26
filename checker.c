/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:10:38 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/26 17:40:58 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int ac)
{
	int	i;

	i = 1;
	while (i + 1 <= stack[0])
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	if (ac - 1 == stack[0])
		return (1);
	return (0);
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

void	sort_all(int **stacks, int ac)
{
	stacks = init_index_stacks(stacks);
	if (is_sorted(stacks[0], ac))
		return ;
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
	free(stacks[0]);
	free(stacks[1]);
	free(stacks[2]);
	free(stacks);
}

int	main(int ac, char **av)
{
	int	**stacks;

	stacks = NULL;
	if (input_check(ac, av) == 1)
	{
		stacks = init_empty_stacks(ac);
		if (stacks)
		{
			stacks = init_num_stacks(ac, av, stacks);
			sort_all(stacks, ac);
			if (is_sorted(stacks[0], ac))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(2, "Error\n", 6);
	}
	else if (input_check(ac, av) == 0)
		write(2, "Error\n", 6);
	return (0);
}
