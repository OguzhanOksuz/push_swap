/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:21:33 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/04 20:00:06 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
# define MY_HEADER_H

# include <stdlib.h>
# include <unistd.h>

char	*input_join(int ac, char **av);
char	**ft_split(char *line, char ch);
int		input_check(char **input);
int		**init_stacks(char **input);
#include <stdio.h>

#endif
