/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:00:31 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 23:25:34 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	ft_atoi(char *line)
{
	int	i;
	int	num;
	int	np;

	i = 0;
	np = 1;
	num = 0;
	if (line[i] == '-')
		np = -1;
	if (line[i] == '-' || line[i] == '+')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		num = (num * 10) + (line[i++] - '0');
	return (num * np);
}

int	**malloc_stacks(char **input)
{
	int	len;
	int	**stacks;

	len = 0;
	while (input[len])
		len++;
	stacks = (int **)malloc(sizeof(int *) * (3));
	if (!stacks)
		return (NULL);
	stacks[0] = (int *)malloc(sizeof(int) * (len + 1));
	if (!stacks[0])
		return (free(stacks), NULL);
	stacks[1] = (int *)malloc(sizeof(int) * (len + 1));
	if (!stacks[1])
		return (free(stacks[0]), free(stacks), NULL);
	stacks[2] = (int *)malloc(sizeof(int) * (len + 1));
	if (!stacks[2])
		return (free(stacks[1]), free(stacks[0]), free(stacks), NULL);
	return (stacks);
}

void	init_numbered(int **stacks, char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	stacks[0][0] = i;
	stacks[1][0] = 0;
	stacks[2][0] = i;
	i = 0;
	while (++i <= stacks[0][0])
	{
		stacks[0][i] = ft_atoi(input[i - 1]);
		stacks[2][i] = stacks[0][i];
	}
}

void	sort_stack(int *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i <= stack[0])
	{
		j = 0;
		while (++j < stack[0])
		{
			if (stack[j] > stack[j + 1])
			{
				tmp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = tmp;
			}
		}
	}
}

int	**init_stacks(char **input)
{
	int	**stacks;
	int	i;
	int	j;

	stacks = malloc_stacks(input);
	if (!stacks)
		return (NULL);
	init_numbered(stacks, input);
	sort_stack(stacks[2]);
	i = 0;
	while (++i <= stacks[0][0])
	{
		j = 1;
		while (stacks[2][j] != stacks[0][i] && j <= stacks[2][0])
			j++;
		stacks[0][i] = j;
	}
	return (stacks);
}
