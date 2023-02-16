/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/16 14:47:27 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		input_num_check(int ac, char **av);
int		input_dup_check(int ac, char **av);
int		input_num_range_check(int ac, char **av);
int		**init_empty_stacks(int ac);
int		**init_num_stacks(int ac, char **av, int **stacks);
int		**init_index_stacks_extension(int **stacks);
int		**init_index_stacks(int **stacks);
int		ft_atoi(char *str);
void	swap(int **stacks, char *str);
void	rotate(int **stacks, char *str);
void	rrotate(int **stacks, char *str);
void	push(int *dststacs, int *srcstack, char *str);
int		short_way_to_mean_val(int *stack, int mean);
void	first_push(int **stacks);

#endif
