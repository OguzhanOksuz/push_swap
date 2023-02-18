/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/19 01:09:08 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		input_num_c(int ac, char **av);
int		input_dup_c(int ac, char **av);
int		input_num_r_c(int ac, char **av);

int		**init_empty_stacks(int ac);
int		**init_num_stacks(int ac, char **av, int **stacks);
int		**init_index_stacks_extension(int **stacks);
int		**init_index_stacks(int **stacks);

int		next_way_to_mean(int *stacks, int mean);
int		get_index(int *stacks, int num);
int		short_way(int *stack, int num);
void	count_b(int **stacks);

int		max_val(int *stack);
int		short_val(int *stack, int num);
int		min_val(int *stack);
int		bigger_val(int *stack, int num);
int		smaller_val(int *stack, int num);

void	swap(int **stacks, char *str);
void	push(int *dststacs, int *srcstack, char *str);
void	rotate(int **stacks, char *str);
void	rrotate(int **stacks, char *str);

void	sort_big(int **stacks);
void	sort_little(int **stacks);

#endif
