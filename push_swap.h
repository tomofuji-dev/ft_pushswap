/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:58:44 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/25 18:32:33 by tfujiwar         ###   ########.fr       */
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

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

typedef struct s_list
{
	int				content;
	t_bool			sentinel;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_list_meta
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	len_a;
	size_t	len_b;
	size_t	len;
}	t_list_meta;

int			*args_to_intlist(int argc, char *argv[]);
t_list_meta	*intlist_to_tlist(int *int_list, int len);

void		exec_cmd(t_list_meta *meta, t_cmd cmd);
t_bool		is_sorted(t_list *head, size_t len);
size_t		get_index(t_list *head, size_t len, int key);

void		swap_a(t_list *stack_a, size_t *len_a);
void		swap_b(t_list *stack_b, size_t *len_b);
void		swap_ab(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b);

void		push_a(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b);
void		push_b(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b);

void		rotate_a(t_list *stack_a, size_t *len_a);
void		rotate_b(t_list *stack_b, size_t *len_b);
void		rotate_ab(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b);

void		rrotate_a(t_list *stack_a, size_t *len_a);
void		rrotate_b(t_list *stack_b, size_t *len_b);
void		rrotate_ab(t_list *stack_a, t_list *stack_b, \
					size_t *len_a, size_t *len_b);

t_list		*list_new(int content, t_bool sentinel);
t_list		*list_last(t_list *head);
void		list_clear(t_list *head);

void		list_addback(t_list *head, t_list *new);
void		list_addfront(t_list *head, t_list *new);
t_list		*list_removefront(t_list *head);
t_list		*list_removeback(t_list *head);

int			ft_atoi(const char *nptr);
void		free_all(t_list *stack_a, t_list *stack_b, int *int_list);
int			*bubble_sort(int *int_list, int len);

#endif	/* PUSH_SWAP_H */