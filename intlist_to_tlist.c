/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist_to_tlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:20:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/26 06:53:34 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_meta	*intlist_to_tlist(int *int_list, int len)
{
	t_list_meta	*meta;
	t_list		*new_node;
	int			i;

	meta = malloc(sizeof(t_list_meta));
	if (!meta)
		free_list(int_list, NULL);
	meta->original_list = int_list;
	meta->len_a = 0;
	meta->len_b = 0;
	meta->stack_a = list_new(-1, TRUE);
	meta->stack_b = list_new(-1, TRUE);
	if (!meta->stack_a || !meta->stack_b)
		free_meta(meta, TRUE);
	i = 0;
	while (i < len)
	{
		new_node = list_new(int_list[i++], FALSE);
		if (!new_node)
			free_meta(meta, TRUE);
		list_addback(meta->stack_a, new_node);
	}
	meta->len_a = (size_t)len;
	meta->len = (size_t)len;
	return (meta);
}
