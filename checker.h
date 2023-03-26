/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:16:50 by ooksuz            #+#    #+#             */
/*   Updated: 2023/03/26 20:02:36 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

int		input_check(int ac, char **av);
int		**init_empty_stacks(int ac);
int		**init_num_stacks(int ac, char **av, int **stacks);
int		str_cmp(char *s1, char *s2);
int		str_cmp(char *s1, char *s2);
void	swap(int **stacks, char *str);
void	rotate(int **stacks, char *str);
void	rrotate(int **stacks, char *str);
void	push(int *dststack, int *srcstack, char *str);
char	*get_next_line(int fd);
#endif
