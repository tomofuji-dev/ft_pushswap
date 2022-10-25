/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:01:05 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/25 17:57:08 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_all(t_list *stack_a, t_list *stack_b, int *int_list)
{
	if (stack_a)
		list_clear(stack_a);
	if (stack_b)
		list_clear(stack_b);
	if (int_list)
		free(int_list);
	write(2, "Error\n", 6);
	exit(1);
}

void	swap_value(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*bubble_sort(int *int_list, int len)
{
	int	*int_list_sorted;
	int	i;
	int	j;

	int_list_sorted = malloc(sizeof(int) * len);
	if (!int_list_sorted)
		return (NULL);
	i = 0;
	while (i++ < len)
		int_list_sorted[i - 1] = int_list[i - 1];
	i = 0;
	while (i++ < len - 1)
	{
		j = i;
		while (j++ < len)
		{
			if (int_list_sorted[i - 1] > int_list_sorted[j - 1])
				swap_value(&int_list_sorted[i - 1], &int_list_sorted[j - 1]);
		}
	}
	return (int_list_sorted);
}
