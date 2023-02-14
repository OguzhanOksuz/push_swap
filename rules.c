/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:33:36 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/14 13:08:59 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **stack, char *str)
{
	if ((stack[0][0] >= 2) && ((str[1] == 'a') || (str[1] == 's')))
	{
		stack[0][1] = stack[0][1] + stack[0][2];
		stack[0][2] = stack[0][1] - stack[0][2];
		stack[0][1] = stack[0][1] - stack[0][2];
	}

	if ((stack[1][0] >= 2) && ((str[1] == 'b') || (str[1] == 's')))
	{
		stack[1][1] = stack[1][1] + stack[1][2];
		stack[1][2] = stack[1][1] - stack[1][2];
		stack[1][1] = stack[1][1] - stack[1][2];
	}
	write(1, &str, 2);
}
