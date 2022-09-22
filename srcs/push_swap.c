/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 14:55:23 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "push_swap_init.h"
#include "quick_sort.h"
#include "ab_table.h"
#include "deque.h"
#include "deque_util.h"
#include "push_swap_util.h"

int	push_swap(size_t len, int *array)
{
	t_abtable	*ab_table;

	ab_table = push_swap_init(len, array);
	if (!ab_table)
		return (false);
	//int test = 0;
	while (can_sort(ab_table, BOTH_TABLE))
	{
		//put_table(ab_table);
		//if (test > 4)
			//break;
		//test++;
		if (can_sort(ab_table, A_TABLE))
		{
			//printf("A_table is not sorted\n");
			divide_ab_table(ab_table, A_TABLE);
		}
		else
		{
			//printf("A_table is sorted\n");
			reverse_a(ab_table);
		}
		if (can_sort(ab_table, B_TABLE))
		{
			//printf("B_table is not sorted\n");
			divide_ab_table(ab_table, B_TABLE);
		}
		//else
			//printf("B_table is sorted\n");
		//reverse_b(ab_table);
	}
	//printf("can_sort\n");
	//put_table(ab_table);
	clear_ab_table(ab_table);
	return (true);
}
