/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:36:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/18 16:59:54 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_little(int **stacks)
{
	if (stacks[0][1] == max_val(stacks[0]))
		rotate(stacks, "ra\n");
	else if (stacks[0][2] == max_val(stacks[0]))
		rrotate(stacks, "rra\n");
	if (stacks[0][1] > stacks[0][2] && stacks[0][0])
		swap(stacks, "sa\n");
}

void	sort_all(int **stacks)
{
	if (stacks[0][0] > 5)
	{
		sort_big(stacks);
	}
	else if (stacks[0][0] > 3)
	{
//		sort_middle(stacks);
	}
	else if (stacks[0][0] == 3)
	{
		sort_little(stacks);
	}
	else if (stacks[0][0] == 2 && stacks[0][1] > stacks[0][2])
	{
		rotate(stacks, "ra\n");
	}
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
	if (ac > 2)
	{
		if (input_num_check(ac, av) && input_dup_check(ac, av))
		{
			if (input_num_range_check(ac, av))
			{
				stacks = init_empty_stacks(ac);
				if (stacks)
				{
					stacks = init_num_stacks(ac, av, stacks);
					stacks = init_index_stacks(stacks);
					sort_all(stacks);
				}
				else
					write(1, "Error\n", 6);
			}
			else
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
}
