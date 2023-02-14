/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:46:23 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/12 01:52:21 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_num_check(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	input_dup_check(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	j = 1;
	while (j < ac)
	{
		i = 1;
		while ((j + i) < ac)
		{
			k = 0;
			while (av[j][k] && av[j + i][k] && av[j][k] == av[j + i][k])
				k++;
			if ((av[j][k] == 0 && av[j + i][k] == 0))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	input_num_range_check(int ac, char **av)
{
	unsigned int	num;
	int				i;
	int				j;
	int				np;

	j = 1;
	while (j < ac)
	{
		np = 1;
		num = 0;
		i = 0;
		if (av[j][i] == '-')
		{
			np = -1;
			i++;
		}
		while (av[j][i])
			num = (10 * num) + (av[j][i++] - '0');
		if ((np == 1 && num > 2147483647) || (np == -1 && num > 2147483648))
			return (0);
		j++;
	}
	return (1);
}
