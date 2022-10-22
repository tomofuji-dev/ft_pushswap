/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 06:04:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/23 07:15:36 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack, size_t *stack_len)
{
	t_list	*first;
	t_list	*second;

	if (*stack_len < 2)
		return ;
	first = stack->next;
	second = first->next;
	if (*stack_len == 2)
	{
		stack->prev = first;
		first->next = stack;
	}
	else
	{
		second->next->prev = first;
		first->next = second->next;
	}
	first->prev = second;
	second->next = first;
	second->prev = stack;
	stack->next = second;
	return ;
}

void	swap_a(t_list *stack_a, size_t *len_a)
{
	write(1, "sa\n", 3);
	return (swap(stack_a, len_a));
}

void	swap_b(t_list *stack_b, size_t *len_b)
{
	write(1, "sb\n", 3);
	return (swap(stack_b, len_b));
}

void	swap_ab(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b)
{
	write(1, "ss\n", 3);
	swap(stack_a, len_a);
	swap(stack_b, len_b);
	return ;
}
