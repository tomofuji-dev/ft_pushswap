/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:01:05 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/28 09:55:15 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_list(int *int_list, int *int_list_sorted)
{
	if (int_list)
		free(int_list);
	if (int_list_sorted)
		free(int_list_sorted);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_meta(t_list_meta *meta, t_bool exit_bool)
{
	if (meta->stack_a)
		list_clear(meta->stack_a);
	if (meta->stack_b)
		list_clear(meta->stack_b);
	if (meta->original_list)
		free(meta->original_list);
	free(meta);
	if (exit_bool)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
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

unsigned int	count_bit_len(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 2 > 0)
	{
		count += 1;
		n /= 2;
	}
	return (count);
}
