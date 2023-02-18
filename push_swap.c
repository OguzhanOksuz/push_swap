/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/18 13:48:47 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_little(int **stacks)
{
	if (stacks[0][1] == max_val(stacks[0]))
		rotate(stacks, "ra\n");
	else if (stacks[0][2] == max_val(stacks[0]))
		rrotate(stacks, "rra\n");
	if (stacks[0][1] > stacks[0][2])
		swap(stacks, "sa\n");
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
				sort_big(stacks);
			}
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
