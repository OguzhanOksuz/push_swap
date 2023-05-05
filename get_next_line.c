/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:34:22 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 12:57:51 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

char	*ft_trim(char *rd)
{
	int		i;
	char	*rt;
	int		len;
	int		j;

	j = 0;
	i = 0;
	len = 0;
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	len = ft_strlen(rd + i);
	rt = (char *)malloc(sizeof(char) * (len + 1));
	while (rd[i])
		rt[j++] = rd[i++];
	rt[j] = 0;
	free (rd);
	return (rt);
}

char	*ft_line(char *rt, char *rd)
{
	int		i;

	i = 0;
	if (!rd)
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	rt = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (rd[i] && rd[i] != '\n')
	{
		rt[i] = rd[i];
		i++;
	}
	if (rd[i] == '\n')
		rt[i++] = '\n';
	rt[i] = 0;
	return (rt);
}

char	*ft_read(int fd, char *rt)
{
	char	*rd;
	int		count;

	count = 1;
	rd = (char *)malloc(sizeof(char) * (4 + 1));
	while (count > 0)
	{
		count = read(fd, rd, 4);
		if (count == -1)
		{
			free(rd);
			return (NULL);
		}
		rd[count] = 0;
		rt = ft_strjoin(rt, rd);
		if (ft_strchr(rt, '\n'))
			break ;
	}
	free (rd);
	return (rt);
}

char	*get_next_line(int fd)
{
	static char	*rd;
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	rd = ft_read(fd, rd);
	if (!rd || ft_strlen(rd) < 1)
	{
		free(rd);
		rd = NULL;
		return (NULL);
	}
	line = ft_line(line, rd);
	rd = ft_trim(rd);
	return (line);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
