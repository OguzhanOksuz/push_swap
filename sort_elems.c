/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooksuz <ooksuz@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:34:04 by ooksuz            #+#    #+#             */
/*   Updated: 2023/02/15 13:37:49 by ooksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_3_elem(int **stacks)
{
	if (stacks[1][1] > stacks[1][2])
		swap(stacks, "sb\n");
	rotate(stacks, "ra\n");
}
