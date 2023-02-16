/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:15 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/16 20:19:08 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	short_way_to_mean_val(int *stack, int mean)
{
	int	i;

	i = 1;
	while (i <= stack[0])
	{
		if (stack[i] <= mean)
			break ;
		i++;
	}
	if (i > stack[0])
		return (0);
	if (i <= stack[0] / 2)
		return (1);
	else
		return (-1);
}

int	step_counts_for_rot_b(int **stacks)
{
	int	i;
	
	i = 1;
	while (i <= stacks[1][0])
	{
		stacks[2][i] = step_counts_for_rot_a(stacks, i);
		i++;
	}
	i = 1;
	while (stacks[2][i] != min_val(stacks[2]))
			i++;
	return (i + stacks[2][i]);
}

int	step_counts_for_rot_a(int **stacks, int	num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stacks[1][num] > max_val(stacks[0]) || stacks[1][num] < min_val(stacks[0]))
	{
		while (stacks[0][num] != min_val(stacks[0]))
			num++;
		if (num - 1 <= stacks[0][0] / 2)
			return (num - 1);
		else
			return (stacks[0][0] - num + 1);
	}
	while (stacks[0][i] != min_val_of_biggers(stacks, stacks[0][num]))
		i++;
	while (stacks[0][j] != max_val_of_smallers(stacks, stacks[0][num]))
		j++;
	if (i > stacks[0][0] / 2)
		i = (stacks[0][0] / 2) - i;
	if (j > stacks[0][0] / 2)
		j = (stacks[0][0] / 2) - j;
	if (i >= j)
		return (i);
	return (j);
}
