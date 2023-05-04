/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:18 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 18:34:36 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_all_num(char	*input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
	       i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicated(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 1;
		while (input[i + j])
		{
			if (ft_strcmp(input[i], input[i + j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	input_check(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_all_num(input[i]) == 0)
			return (0);
		i++;
	}
	if (is_duplicated(input) == 0)
		return (0);
	return (1);
}
