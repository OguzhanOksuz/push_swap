/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:36:58 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/20 20:47:32 by Ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		input_check(int ac, char **av);

int		**init_empty_stacks(int ac);
int		**init_num_stacks(int ac, char **av, int **stacks);
int		**init_index_stacks_extension(int **stacks);
int		**init_index_stacks(int **stacks);

void	checker_swap(int **stacks, char *str);
void	checker_push(int *dststacs, int *srcstack);
void	checker_rotate(int **stacks, char *str);
void	checker_rrotate(int **stacks, char *str);

#endif
