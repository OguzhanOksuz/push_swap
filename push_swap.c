/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/14 19:39:46 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void (int **stacks)
{
	int	i;
}

int	chunk_num(int num)
{
	if (num < 21)
		return (1);
	if (num < 41)
		return (2);
	if (num < 61)
		return (3);
	if (num < 81)
		return (4);
	if (num < 101)
		return (5);
}


int	ft_atoi(char *str)
{
	unsigned int	num;
	int				np;
	int				i;

	num = 0;
	np = 1;
	i = 0;
	if (str[i] == '-')
	{
		np = -1;
		i++;
	}
	while (str[i])
		num = (num * 10) + (str[i++] - '0');
	return (num * np);
}

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
			}
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
