/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:33:36 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/26 19:44:55 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **stacks, char *str)
{
	if ((stacks[0][0] >= 2) && ((str[1] == 'a') || (str[1] == 's')))
	{
		stacks[0][1] = stacks[0][1] + stacks[0][2];
		stacks[0][2] = stacks[0][1] - stacks[0][2];
		stacks[0][1] = stacks[0][1] - stacks[0][2];
	}
	if ((stacks[1][0] >= 2) && ((str[1] == 'b') || (str[1] == 's')))
	{
		stacks[1][1] = stacks[1][1] + stacks[1][2];
		stacks[1][2] = stacks[1][1] - stacks[1][2];
		stacks[1][1] = stacks[1][1] - stacks[1][2];
	}
	if (str[0] != 0)
		write(1, str, 3);
}

void	rotate(int **stacks, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	if ((str[1] == 'a' || str[1] == 'r') && stacks[0][0] > 1)
	{
		tmp = stacks[0][1];
		while (++i + 1 <= stacks[0][0])
			stacks[0][i] = stacks[0][i + 1];
		stacks[0][i] = tmp;
	}
	i = 0;
	if ((str[1] == 'b' || str[1] == 'r') && stacks[1][0] > 1)
	{
		tmp = stacks[1][1];
		while (++i + 1 <= stacks[1][0])
			stacks[1][i] = stacks[1][i + 1];
		stacks[1][i] = tmp;
	}
	if (str[0] != 0)
		write(1, str, 3);
}

void	rrotate(int **stacks, char *str)
{
	int	i;
	int	tmp;

	i = stacks[0][0] + 1;
	if ((str[2] == 'a' || str[2] == 'r') && stacks[0][0] > 1)
	{
		tmp = stacks[0][i - 1];
		while (--i > 1)
			stacks[0][i] = stacks[0][i - 1];
		stacks[0][i] = tmp;
	}
	i = stacks[1][0] + 1;
	if ((str[2] == 'b' || str[2] == 'r') && stacks[1][0] > 1)
	{
		tmp = stacks[1][i - 1];
		while (--i > 1)
			stacks[1][i] = stacks[1][i - 1];
		stacks[1][1] = tmp;
	}
	if (str[0] != 0)
		write(1, str, 4);
}

void	push(int *dststack, int *srcstack, char *str)
{
	int	i;

	i = dststack[0];
	if (srcstack[0] == 0)
		return ;
	while (i > 0)
	{
		dststack[i + 1] = dststack[i];
		i--;
	}
	dststack[1] = srcstack[1];
	i = 1;
	while (i < srcstack[0])
	{
		srcstack[i] = srcstack[i + 1];
		i++;
	}
	srcstack[i] = 0;
	dststack[0]++;
	srcstack[0]--;
	if (str[0] != 0)
		write(1, str, 3);
}
