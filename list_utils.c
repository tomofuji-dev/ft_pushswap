/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:04:16 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/21 14:18:04 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*list_new(int content, t_bool sentinel)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->sentinel = sentinel;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}

t_list	*list_last(t_list *head)
{
	t_list	*p;

	p = head;
	while (p->next && p->next->sentinel == FALSE)
		p = p->next;
	return (p);
}

t_list	*list_addback(t_list *head, t_list *new)
{
	t_list	*tail;

	tail = list_last(head);
	tail->next = new;
	new->prev = tail;
	new->next = head;
	head->prev = new;
}

t_list	*list_addfront(t_list *head, t_list *new)
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

void	list_clear(t_list *head)
{
	t_list	*tmp;
	t_list	*next;

	if (head->next == NULL)
	{
		free(head);
		return ;
	}
	tmp = head->next;
	while (tmp->sentinel == FALSE)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(tmp);
	return ;
}
