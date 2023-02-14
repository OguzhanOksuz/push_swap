/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/14 13:11:41 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
int	input_num_check(int ac, char **av);
int	input_dup_check(int ac, char **av);
int	input_num_range_check(int ac, char **av);
int	**init_empty_stacks(int ac);
int	**init_num_stacks(int ac, char **av, int **stacks);
int	**init_index_stacks_extension(int **stacks);
int	**init_index_stacks(int **stacks);
int	ft_atoi(char *str);
void	swap(int **stacks, char *str);

#endif
