/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:08:47 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/17 19:29:52 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rrotate(int **stacks, char *str)
{
	int	i;
	int	tmp;

	i = stacks[0][0];
	tmp = stacks[0][i];
	while (i > 1)
	{
		stacks[0][i] = stacks[0][i - 1];
		i--;
	}
	stacks[0][i] = tmp;
	i = stacks[1][0];
	tmp = stacks[1][i];
	while (i > 1)
	{
		stacks[1][i] = stacks[1][i - 1];
		i--;
	}
	stacks[1][i] = tmp;
	write(1, str, 4);
}

void	double_rotate(int **stacks, char *str)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stacks[0][1];
	while (i + 1 <= stacks[0][0])
	{
		stacks[0][i] = stacks[0][i + 1];
		i++;
	}
	stacks[0][i] = tmp;
	i = 1;
	tmp = stacks[1][1];
	while (i + 1 <= stacks[1][0])
	{
		stacks[1][i] = stacks[1][i + 1];
		i++;
	}
	stacks[1][i] = tmp;
	write(1, str, 3);
}

int	return_val(int i, int j)
{
	if (i > 0 && j > 0)
	{
		if (i <= j)
		{
			return (i);
		}
		else
			return (j);
	}
	else if (i < 0 && j < 0)
	{
		if (i <= j)
		{
			return (j);
		}
		else
			return (i);
	}
	return (0);
}

int	rot_val(int **s)
{
	int	i;
	int	j;
	int	indexx;

	indexx = get_index(s[2], min_val(s[2]));
	if (indexx <= s[1][0] / 2)
		i = indexx;
	else
		i = -1 * (s[1][0] - indexx + 1);
	if (s[1][indexx] > max_val(s[0]))
		indexx = get_index(s[0], min_val(s[0]));
	else
		indexx = get_index(s[0], bigger_val(s[0],s[1][indexx]));
	if (indexx  <= (s[0][0] + 1) / 2)
		j = indexx;
	else
		j = -1 * (s[0][0] - indexx);
	return (return_val(i, j));
}
