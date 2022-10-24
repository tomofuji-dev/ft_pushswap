/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:02:25 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/24 14:44:37 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*int_list;
	t_list_meta	*meta;

	if (argc < 2)
		return (-1);
	int_list = args_to_intlist(argc, argv);
	meta = intlist_to_tlist(int_list, argc - 1);
	free(int_list);
	// sort(meta);
	free(meta);
	return (1);
}
