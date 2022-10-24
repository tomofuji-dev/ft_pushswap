/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:04:01 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/24 14:45:18 by tfujiwar         ###   ########.fr       */
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
	int			*int_list;
	t_list_meta	*meta;

	if (argc < 2)
		return (-1);
	int_list = args_to_intlist(argc, argv);
	meta = intlist_to_tlist(int_list, argc - 1);
	free(int_list);
	print_stack(meta->stack_a);
	free(meta);
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	int	*int_list;
// 	int	i;

// 	int_list = args_to_intlist(argc, argv);
// 	i = 0;
// 	printf("[");
// 	while (i < argc - 1)
// 	{
// 		printf("%d ", int_list[i]);
// 		i++;
// 	}
// 	printf("]\n");
// }