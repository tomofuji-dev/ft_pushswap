/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:56:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/26 06:11:33 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *stack, size_t *stack_len)
{
	t_list	*move_node;

	if (*stack_len < 2)
		return ;
	move_node = list_removefront(stack);
	list_addback(stack, move_node);
}

void	rotate_a(t_list *stack_a, size_t *len_a)
{
	write(1, "ra\n", 3);
	rotate(stack_a, len_a);
}

void	rotate_b(t_list *stack_b, size_t *len_b)
{
	write(1, "rb\n", 3);
	rotate(stack_b, len_b);
}

void	rotate_ab(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a, len_a);
	rotate(stack_b, len_b);
}
