/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:22:07 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/18 15:04:26 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_val(int *stack, int num)
{
	int	i;

	i = get_index(stack, num);
	if (i <= stack[0] / 2)
		return (i - 1);
	return (stack[0] - i + 1);
}

int	max_val(int *stack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = 0;
	while (i <= stack[0])
	{
		if (stack[i] > tmp)
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	min_val(int *stack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack[1];
	while (i <= stack[0])
	{
		if (stack[i] < tmp)
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	bigger_val(int *stack, int num)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = max_val(stack);
	while (i <= stack[0])
	{
		if (stack[i] > num && stack[i] < tmp)
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	smaller_val(int *stack, int num)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = min_val(stack);
	while (i <= stack[0])
	{
		if (stack[i] < num && stack[i] > tmp)
			tmp = stack[i];
		i++;
	}	
	return (tmp);
}
