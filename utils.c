/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:01:05 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/24 10:08:26 by tfujiwar         ###   ########.fr       */
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
	write(1, "Error\n", 6);
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

static int	process_digit(const char *nptr, long code)
{
	long	n;
	long	d;

	n = 0;
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		d = *nptr++ - '0';
		if (code > 0)
		{
			if (n <= (LONG_MAX - d) / 10)
				n = 10 * n + d;
			else
				return (-1);
		}
		else
		{
			if (n >= (LONG_MIN + d) / 10)
				n = 10 * n - d;
			else
				return (0);
		}
	}
	return ((int) n);
}

int	ft_atoi(const char *nptr)
{
	long	code;

	while (((*nptr >= '\t') && (*nptr <= '\r')) || (*nptr == ' '))
		nptr++;
	code = 1;
	if (*nptr == '-')
	{
		code *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (process_digit(nptr, code));
}
