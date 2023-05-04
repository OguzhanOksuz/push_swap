/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:51:49 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 17:22:55 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	error_handler_a2(char **list, int num)
{
	int	i;

	i = 0;
	while (i < num)
		free(list[i++]);
	free(list);
}

int	word_count(char *line, char ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ch)
			i++;
		if (line[i] != 0 && line[i] != ch)
		{
			count++;
		}
		while (line[i] && line[i] != ch)
			i++;
	}
	return (count);
}

char	*ft_substr(char *str, int len)
{
	char	*rt;
	int		i;

	rt = (char *)malloc(sizeof(char) * (len + 1));
	if (!rt)
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		rt[i] = str[i];
		i++;
	}
	rt[i] = 0;
	return (rt);
}

char	**ft_split(char *line, char ch)
{
	int		i;
	int		len;
	char	**list;

	list = (char **)malloc(sizeof(char *) * (word_count(line, ch) + 1));
	if (!list)
		return (NULL);
	i = 0;
	while (*line)
	{
		while (*line == ch)
			line++;
		len = 0;
		while (line[len] != 0 && line[len] != ch)
			len++;
		if (*line == 0)
			continue ;
		list[i] = ft_substr(line, len);
		if (!list[i++])
			return (error_handler_a2(list, i - 1), NULL);
		while (*line != 0 && *line != ch)
			line++;
	}
	list[i] = 0;
	return (list);
}
