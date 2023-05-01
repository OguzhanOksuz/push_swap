/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:37:38 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/01 15:03:58 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int wordcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

char *ft_substr(char *s1, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);

}

char *next_word(char *str)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (ft_substr(str, len));
}

char	**ft_split(char *str)
{
	int		count;
	int		i;
	char	**arr;

	if (!str)
		return (NULL);
	count = wordcount(str);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while(*str)
	{
		if (*str != ' ')
		{
			arr[i++] = next_word(str);
			while (*str != ' ' && *str)
				str++;
			if (*str == 0)
				break ;	
		}
		str++;
	}
	arr[i] = 0;
	return (arr);
}
