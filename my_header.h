/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:21:33 by ooksuz            #+#    #+#             */
/*   Updated: 2023/05/07 17:40:01 by ooksuz           ###   ########.fr       */
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
int		is_sorted(int *stacks);

void	swap(int **stacks, char *str);
void	rotate(int **stacks, char *str);
void	rrotate(int **stacks, char *str);
void	push(int *dst, int *src, char *str);

int		get_index(int *stack, int num);
int		next_way_to_mean(int *stacks, int mean);
int		short_way(int *stack, int num);
void	count_b(int **stacks);

int		short_val(int *stack, int num);
int		min_val(int *stack);
int		max_val(int *stack);
int		bigger_val(int *stack, int num);

void	sort_little(int **stacks);
void	sort_big(int **stacks);
void	sort_all(int **stacks);

int		scmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**get_prompt(void);
void	checker(int **stacks, char **prompt);

#endif
