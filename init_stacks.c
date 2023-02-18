/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:59:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/19 01:09:01 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	**init_empty_stacks(int ac)
{
	int	**stacks;

	stacks = (int **)malloc(sizeof(int *) * 3);
	if (!stacks)
		return (0);
	stacks[0] = (int *)malloc(sizeof(int) * ac);
	if (!stacks[0])
		return (0);
	stacks[1] = (int *)malloc(sizeof(int) * ac);
	if (!stacks[1])
		return (0);
	stacks[2] = (int *)malloc(sizeof(int) * ac);
	if (!stacks[2])
		return (0);
	return (stacks);
}

int	**init_num_stacks(int ac, char **av, int **stacks)
{
	int	i;

	stacks[0][0] = ac - 1;
	stacks[1][0] = 0;
	stacks[2][0] = ac - 1;
	i = 1;
	while (i < ac)
	{
		stacks[0][i] = ft_atoi(av[i]);
		stacks[2][i] = ft_atoi(av[i]);
		i++;
	}
	return (stacks);
}

int	**init_index_stacks_extension(int **stacks)
{
	int	i;
	int	j;

	i = 1;
	while (i <= stacks[0][0])
	{
		j = 1;
		while (j <= stacks[2][0])
		{
			if (stacks[0][i] == stacks[2][j])
			{
				stacks[0][i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (stacks);
}

int	**init_index_stacks(int **stacks)
{
	int	i;
	int	j;

	i = 1;
	while (i <= stacks[2][0])
	{
		j = 1;
		while (j + 1 <= stacks[2][0])
		{
			if (stacks[2][j] > stacks[2][j + 1])
			{
				stacks[2][j] = stacks[2][j] + stacks[2][j + 1];
				stacks[2][j + 1] = stacks[2][j] - stacks[2][j + 1];
				stacks[2][j] = stacks[2][j] - stacks[2][j + 1];
			}
			j++;
		}
		i++;
	}
	return (init_index_stacks_extension(stacks));
}
