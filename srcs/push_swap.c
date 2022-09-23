/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 01:55:29 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "push_swap_init.h"
#include "quick_sort.h"
#include "ab_table.h"
#include "deque.h"
#include "push_swap_util.h"
#include "ab_table_util.h"

int	push_swap(size_t len, int *array)
{
	t_abtable	*ab_table;

	ab_table = push_swap_init(len, array);
	if (!ab_table)
		return (false);
	int test = 0;
	while (can_sort(ab_table, BOTH_TABLE))
	{
		put_table(ab_table);
		if (test > 9)
			break;
		test++;
		//if (is_less_than_four_table_a(table))
		//{
//
		//}

		init_flag(ab_table, BOTH_TABLE);
		if (can_sort(ab_table, A_TABLE))
		{
			//printf("A_table is not sorted\n");
			divide_ab_table(ab_table, A_TABLE);
			//reverse_a(ab_table);
		}
		if (!can_sort(ab_table, A_TABLE))
		{
			//printf("can_sort == false so execute reverse_a\n");
			reverse_a(ab_table);
		}
		//else
		//{
			//printf("A_table is sorted\n");
		//}
		put_table(ab_table);
		if (can_sort(ab_table, A_TABLE) == false && can_sort(ab_table, B_TABLE))
		{
			//printf("B_table is not sorted. so execute diviede_ab_table\n");
			divide_ab_table(ab_table, B_TABLE);
		}
		else
		{
			//reverse_a(ab_table);
			//reverse_a(ab_table);
			//printf("B_table is sorted\n");
		}
		//reverse_a(ab_table);
		//reverse_b(ab_table);
	}
	printf("\n\n test=%d,end_sort\n", test);
	put_table(ab_table);
	clear_ab_table(ab_table);
	return (true);
}
