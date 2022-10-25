/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_intlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:33:03 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/26 06:53:22 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	handle_digit(int *int_list, int i, char *tmp, int sign)
{
	int	tmp_digit;
	int	n;

	n = 0;
	while ((*tmp >= '0') && (*tmp <= '9'))
	{
		tmp_digit = *tmp++ - '0';
		if (sign > 0)
		{
			if (n <= (INT_MAX - tmp_digit) / 10)
				n = 10 * n + tmp_digit;
			else
				free_list(int_list, NULL);
		}
		else
		{
			if (n >= (INT_MIN + tmp_digit) / 10)
				n = 10 * n - tmp_digit;
			else
				free_list(int_list, NULL);
		}
	}
	if (*tmp != '\0')
		free_list(int_list, NULL);
	int_list[i - 1] = n;
}

static void	atoi_argv(int *int_list, char *argv[], int i)
{
	char	*tmp;
	int		sign;

	sign = 1;
	tmp = argv[i];
	if (*tmp == '-')
	{
		sign = -1;
		tmp++;
	}
	if (!((*tmp >= '0') && (*tmp <= '9')))
		free_list(int_list, NULL);
	handle_digit(int_list, i, tmp, sign);
}

static t_bool	check_multi(int *int_list_sorted, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (int_list_sorted[i] == int_list_sorted[i + 1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	coord_compress(int *int_list, int len)
{
	int	*int_list_sorted;
	int	i;
	int	j;

	int_list_sorted = bubble_sort(int_list, len);
	if (!int_list_sorted)
		free_list(int_list, NULL);
	if (check_multi(int_list_sorted, len))
		free_list(int_list, int_list_sorted);
	i = 0;
	while (i++ < len)
	{
		j = 0;
		while (j++ < len)
		{
			if (int_list[i - 1] == int_list_sorted[j - 1])
			{
				int_list[i - 1] = j - 1;
				break ;
			}
		}
	}
}

int	*args_to_intlist(int argc, char *argv[])
{
	int	*int_list;
	int	i;

	int_list = malloc(sizeof(int) * (argc - 1));
	if (!int_list)
		free_list(int_list, NULL);
	i = 1;
	while (i < argc)
	{
		atoi_argv(int_list, argv, i);
		i++;
	}
	coord_compress(int_list, argc - 1);
	return (int_list);
}
