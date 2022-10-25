/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:28:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/24 09:55:01 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
	{
		printf("%s", "stack is NULL\n");
		return ;
	}
	else if (!stack->next)
	{
		printf("%s", "stack is empty\n");
		return ;
	}
	printf("[");
	tmp = stack->next;
	while (tmp->next->sentinel == FALSE)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("%d]\n", tmp->content);
	return ;
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_node;
	size_t	len_a;
	size_t	len_b;

	if (argc < 2)
	{
		write(1, "argc Error\n", 11);
		return (-1);
	}
	len_a = 0;
	len_b = 0;
	stack_a = list_new(0, TRUE);
	stack_b = list_new(0, TRUE);
	if (!stack_a || !stack_b)
		free_all(stack_a, stack_b, NULL);
	while (len_a < (size_t)argc - 1)
	{
		new_node = list_new(ft_atoi(argv[len_a + 1]), FALSE);
		if (!new_node)
			free_all(stack_a, stack_b, NULL);
		list_addback(stack_a, new_node);
		len_a++;
	}
	printf("===== init =====\n");
	printf("stack a: \n");
	print_stack(stack_a);
	printf("stack b: \n");
	print_stack(stack_b);
	int i = 0;
	while (i++ < 5)
	{
		printf("===== push_b =====\n");
		push_b(stack_a, stack_b, &len_a, &len_b);
		printf("stack a: \n");
		print_stack(stack_a);
		printf("stack b: \n");
		print_stack(stack_b);
	}
	while (i-- > 0)
	{
		printf("===== push_a =====\n");
		push_a(stack_a, stack_b, &len_a, &len_b);
		printf("stack a: \n");
		print_stack(stack_a);
		printf("stack b: \n");
		print_stack(stack_b);
	}
	return (1);
}