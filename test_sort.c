/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:25 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/25 18:57:15 by tfujiwar         ###   ########.fr       */
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

void	sort_3elems(t_list_meta *meta)
{
	int	a;
	int	b;
	int	c;

	a = meta->stack_a->next->content;
	b = meta->stack_a->next->next->content;
	c = meta->stack_a->next->next->next->content;
	if (a > b && b > c)
	{
		exec_cmd(meta, SA);
		exec_cmd(meta, RRA);
	}
	else if (a > b && b < c && a > c)
		exec_cmd(meta, RA);
	else if (a > b && b < c && a < c)
		exec_cmd(meta, SA);
	else if (a < b && b > c && a > c)
		exec_cmd(meta, RRA);
	else if (a < b && b > c && a < c)
	{
		exec_cmd(meta, SA);
		exec_cmd(meta, RA);
	}
}

void	sort_under_3elems(t_list_meta *meta)
{
	if (meta->len == 1)
		return ;
	else if (meta->len == 2)
	{
		if (meta->stack_a->next->content > meta->stack_a->next->next->content)
			exec_cmd(meta, SA);
		return ;
	}
	else
		sort_3elems(meta);
}

void	sort_under_6elems(t_list_meta *meta)
{
	size_t	i;
	size_t	key_index;
	size_t	j;

	i = 0;
	while (meta->len_a > 3)
	{
		j = 0;
		key_index = get_index(meta->stack_a, meta->len_a, i);
		while (j++ < key_index)
			exec_cmd(meta, RA);
		exec_cmd(meta, PB);
		i++;
	}
	sort_3elems(meta);
	while (meta->len_b > 0)
		exec_cmd(meta, PA);
}

// void	sort_over_7elems(t_list_meta *meta)
// {
// 	return ;
// }

int	main(int argc, char *argv[])
{
	int			*int_list;
	t_list_meta	*meta;

	if (argc < 2)
		return (-1);
	int_list = args_to_intlist(argc, argv);
	meta = intlist_to_tlist(int_list, argc - 1);
	free(int_list);
	if (is_sorted(meta->stack_a, meta->len_a))
		return (-1);
	if (argc - 1 <= 3)
		sort_under_3elems(meta);
	else if (argc - 1 <= 6)
		sort_under_6elems(meta);
	// else
	// 	sort_over_7elems(meta);
	print_stack(meta->stack_a);
	print_stack(meta->stack_b);
	free(meta);
	return (1);
}