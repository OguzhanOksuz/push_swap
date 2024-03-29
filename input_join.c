/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:42:19 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 23:21:51 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	ft_strlen(char *s1)
{
	int	len;

	len = 0;
	if (!s1)
		return (len);
	while (s1[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*rt;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	rt = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	while (*s2)
		rt[i++] = *s2++;
	rt[i] = 0;
	free(s1);
	return (rt);
}

char	*ft_join(char *s1, char *s2, char ch)
{
	char	*line;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	line = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (!line)
		return (free(s1), NULL);
	i = -1;
	while (++i < len1)
		line[i] = s1[i];
	line[i] = ch;
	free(s1);
	i = -1;
	while (++i < len2)
		line[len1 + 1 + i] = s2[i];
	line[len1 + len2 + 1] = 0;
	return (line);
}

char	*input_join(int ac, char **av)
{
	int		i;
	char	*line;

	line = 0;
	i = 1;
	while (i < ac)
	{
		line = ft_join(line, av[i++], ' ');
		if (!line)
			exit(write(2, "Error\n", 6) - 5);
	}
	return (line);
}
