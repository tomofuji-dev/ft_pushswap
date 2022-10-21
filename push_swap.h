/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:58:44 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/21 14:18:29 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE	0
# define TRUE	1

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	int				content;
	t_bool			sentinel;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*list_new(int content, t_bool sentinel);
t_list	*list_last(t_list *head);
t_list	*list_addback(t_list *head, t_list *new);
t_list	*list_addfront(t_list *head, t_list *new);
void	list_clear(t_list *head);

#endif	/* PUSH_SWAP_H */