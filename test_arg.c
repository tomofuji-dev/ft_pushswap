/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:04:01 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/24 11:28:19 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*int_list;
	int	i;

	int_list = args_to_intlist(argc, argv);
	i = 0;
	printf("[");
	while (i < argc - 1)
	{
		printf("%d ", int_list[i]);
		i++;
	}
	printf("]\n");
}
