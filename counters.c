/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/18 14:28:51 by ooksuz           ###   ########.fr       */
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

int	short_way(int *stack, int num)
{
	int	i;

	i = get_index(stack, num);
	if (i == 1)
		return (0);
	if (i <= stack[0] / 2)
		return (i - 1);
	else
		return (i - stack[0] - 1);
}

void	count_b(int **s)
{
	int	i;

	i = 1;
	s[2][0] = s[1][0];
	while (i <= s[1][0])
	{
		if (s[1][i] > max_val(s[0]))
			s[2][i] = short_val(s[0], min_val(s[0]));
		else
			s[2][i] = short_val(s[0], bigger_val(s[0], s[1][i]));
		s[2][i] += short_val(s[1], s[1][i]);
		i++;
	}
	s[2][s[2][0] + 1] = s[1][get_index(s[2], min_val(s[2]))];
}
