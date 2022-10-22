/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:58:44 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/23 08:31:43 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void	swap_a(t_list *stack_a, size_t *len_a);
void	swap_b(t_list *stack_b, size_t *len_b);
void	swap_ab(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b);

void	push_a(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b);
void	push_b(t_list *stack_a, t_list *stack_b, size_t *len_a, size_t *len_b);

t_list	*list_new(int content, t_bool sentinel);
t_list	*list_last(t_list *head);
void	list_clear(t_list *head);

void	list_addback(t_list *head, t_list *new);
void	list_addfront(t_list *head, t_list *new);
t_list	*list_removefront(t_list *head);
t_list	*list_removeback(t_list *head);

int		ft_atoi(const char *nptr);
void	free_all(t_list *stack_a, t_list *stack_b);

#endif	/* PUSH_SWAP_H */