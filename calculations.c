/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:12:24 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/15 11:07:36 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	max_val(int **stacks, int c)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stacks[c][1];
	while (i <= stacks[c][0])
	{
		if (stacks[c][i] > tmp)
			tmp = stacks[c][i];
		i++;
	}
	return (tmp);
}

int	min_val(int **stacks, int c)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stacks[c][1];
	while (i <= stacks[c][0])
	{
		if (stacks[c][i] < tmp)
			tmp = stacks[c][i];
		i++;
	}
	return (tmp);
}

int	mean_val(int **stacks, int c)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	while (i <= stacks[c][0])
	{
		sum += stacks[c][i];
		i++;
	}
	return (sum / i);
}

int	short_way_to_val(int **stacks, int c, int mean)
{
	int	i;
	int	j;

	i = 1;
	while (i <= stacks[c][0])
	{
		if (stacks[c][i] <= mean)
			break ;
		i++;
	}
	j = stacks[c][0];
	while (j >= 1)
	{
		if (stacks[c][j] <= mean)
			break ;
		j--;
	}
	if (i >= stacks[c][0] && j == 0)
		return (0);
	else
		return (j - i);
}
