/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:57:29 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/25 18:46:42 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_cmd(t_list_meta *meta, t_cmd cmd)
{
	if (cmd == SA)
		swap_a(meta->stack_a, &(meta->len_a));
	else if (cmd == SB)
		swap_b(meta->stack_b, &(meta->len_b));
	else if (cmd == SS)
		swap_ab(meta->stack_a, meta->stack_b, &(meta->len_a), &(meta->len_b));
	else if (cmd == PA)
		push_a(meta->stack_a, meta->stack_b, &(meta->len_a), &(meta->len_b));
	else if (cmd == PB)
		push_b(meta->stack_a, meta->stack_b, &(meta->len_a), &(meta->len_b));
	else if (cmd == RA)
		rotate_a(meta->stack_a, &(meta->len_a));
	else if (cmd == RB)
		rotate_b(meta->stack_b, &(meta->len_b));
	else if (cmd == RR)
		rotate_ab(meta->stack_a, meta->stack_b, &(meta->len_a), &(meta->len_b));
	else if (cmd == RRA)
		rrotate_a(meta->stack_a, &(meta->len_a));
	else if (cmd == RRB)
		rrotate_b(meta->stack_b, &(meta->len_b));
	else if (cmd == RRR)
		rrotate_ab(meta->stack_a, meta->stack_b, \
					&(meta->len_a), &(meta->len_b));
}

t_bool	is_sorted(t_list *head, size_t len)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = head;
	while (i++ < len)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

size_t	get_index(t_list *head, size_t len, int key)
{
	size_t	i;
	t_list	*tmp;

	tmp = head->next;
	i = 0;
	while (i < len)
	{
		if (tmp->content == key)
			return (i);
		else
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
