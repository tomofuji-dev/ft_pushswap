/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 07:55:48 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/23 08:36:54 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_addback(t_list *head, t_list *new)
{
	t_list	*tail;

	tail = list_last(head);
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

void	list_addfront(t_list *head, t_list *new)
{
	t_list	*p;

	if (head->next)
		p = head->next;
	else
		p = head;
	head->next = new;
	new->prev = head;
	new->next = p;
	p->prev = new;
}

t_list	*list_removefront(t_list *head)
{
	t_list	*move_node;

	move_node = head->next;
	if (!move_node)
		return (NULL);
	if (move_node->next == head)
	{
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		head->next = move_node->next;
		move_node->next->prev = head;
	}
	move_node->next = NULL;
	move_node->prev = NULL;
	return (move_node);
}

t_list	*list_removeback(t_list *head)
{
	t_list	*move_node;

	move_node = list_last(head);
	if (move_node == head)
		return (NULL);
	if (move_node->prev == head)
	{
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		head->prev = move_node->prev;
		move_node->prev->next = head;
	}
	move_node->next = NULL;
	move_node->prev = NULL;
	return (move_node);
}
