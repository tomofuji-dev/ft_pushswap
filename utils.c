/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:01:05 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/21 14:19:08 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_all(int *intlist, t_list *a, t_list *b)
{
	if (intlist)
		free(intlist);
	if (a)
		list_clear(a);
	if (b)
		list_clear(b);
	return ;
}
