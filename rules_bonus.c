/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:33:36 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/20 20:46:48 by Ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker_swap(int **stacks, char *str)
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
}

void	checker_rotate(int **stacks, char *str)
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
}

void	checker_rrotate(int **stacks, char *str)
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
}

void	checker_push(int *dststack, int *srcstack)
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
}
