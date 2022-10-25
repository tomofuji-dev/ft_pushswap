/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:17:40 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/26 06:11:53 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list *stack, size_t *stack_len)
{
	t_list	*move_node;

	if (*stack_len < 2)
		return ;
	move_node = list_removeback(stack);
	list_addfront(stack, move_node);
}

void	rrotate_a(t_list *stack_a, size_t *len_a)
{
	write(1, "ra\n", 3);
	rrotate(stack_a, len_a);
}

void	rrotate_b(t_list *stack_b, size_t *len_b)
{
	write(1, "rb\n", 3);
	rrotate(stack_b, len_b);
}

void	rrotate_ab(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b)
{
	write(1, "rr\n", 3);
	rrotate(stack_a, len_a);
	rrotate(stack_b, len_b);
}
