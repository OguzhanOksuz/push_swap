/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:34:39 by Ooksuz            #+#    #+#             */
/*   Updated: 2023/05/05 13:01:26 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
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