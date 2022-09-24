/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 02:42:31 by hsano            ###   ########.fr       */
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
#include "two_or_three_node.h"

int	push_swap(size_t len, int *array)
{
	t_abtable	*ab_table;

	ab_table = push_swap_init(len, array);
	if (!ab_table)
		return (false);
	while (can_sort(ab_table, BOTH_TABLE))
	{
		if (is_two_or_three_node(ab_table))
			two_or_three_node(ab_table);
		if (can_sort(ab_table, A_TABLE))
			divide_ab_table(ab_table, A_TABLE);
		if (!can_sort(ab_table, A_TABLE))
			reverse_a(ab_table);
		if (can_sort(ab_table, A_TABLE) == false && can_sort(ab_table, B_TABLE))
			divide_ab_table(ab_table, B_TABLE);
		init_flag(ab_table, BOTH_TABLE);
	}
	clear_ab_table(ab_table);
	return (true);
}
