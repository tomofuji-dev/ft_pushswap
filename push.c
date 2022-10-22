/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 07:47:24 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/23 08:27:50 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *dest, t_list *src, size_t *dest_len, size_t *src_len)
{
	t_list	*move_node;

	if (*src_len == 0)
		return ;
	move_node = list_removefront(src);
	list_addfront(dest, move_node);
	*dest_len += 1;
	*src_len -= 1;
}

void	push_a(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b)
{
	write(1, "pa\n", 3);
	push(stack_a, stack_b, len_a, len_b);
}

void	push_b(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b)
{
	write(1, "pb\n", 3);
	push(stack_b, stack_a, len_b, len_a);
}
