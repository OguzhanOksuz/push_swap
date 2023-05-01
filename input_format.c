/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:29:29 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/01 16:05:53 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_new_ac(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*res;

	len1 = ft_strlen2(s1);
	len2 = ft_strlen2(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	res[len1] = ' ';
	i = -1;
	while (++i < len2)
		res[len1 + i + 1] = s2[i];
	res[len1 + len2 + 1] = 0;
	return (res);
}

char **input_format(int ac, char **av)
{
	int 	i;
	char	*input;

	input = av[1];
	i = 2;
	while (i < ac)
	{
		input = ft_strjoin2(input, av[i++]);
		if (!input)
			return (NULL);
	}
	return (ft_split(input));
}
