/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:12:24 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/15 14:44:45 by ooksuz           ###   ########.fr       */
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

int	max_val(int *stack)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = stack[1];
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
	int	i;
	int	tmp;

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

int	mean_val(int *stack)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	while (i <= stack[0])
	{
		sum += stack[i];
		i++;
	}
	return (sum / i);
}

int	short_way_to_val(int *stack, int mean)
{
	int	i;
	int	j;

	i = 1;
	while (i <= stack[0])
	{
		if (stack[i] >= mean)
			break ;
		i++;
	}
	j = stack[0];
	while (j >= 1)
	{
		if (stack[j] >= mean)
			break ;
		j--;
	}
	if (i >= stack[0] && j <= 1)
		return (0);
	else
		return (j - i);
}
