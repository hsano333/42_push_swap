/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab_table_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:57:03 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 04:07:54 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

t_deque	*execute_shift(t_abtable *table, char target, \
									t_pivot pivot, t_deque *node)
{
	t_deque	*nil_node;

	if (table->ra_flag == true || table->rb_flag == true)
		return (node);
	nil_node = search_nil(node);
	if (is_ss(table, pivot))
	{
		ss(table);
	}
	else if (is_sb(table, target, pivot))
	{
		sb(table);
	}
	else if (is_sa(table, target, pivot))
	{
		sa(table);
	}
	else
		return (node);
	return (nil_node->next);
}

int	execute_reverse(t_abtable *table)
{
	int		cnt_a;
	int		cnt_b;
	t_deque	*node_a;
	t_deque	*node_b;

	node_a = search_nil(table->a)->prev;
	node_b = search_nil(table->b)->prev;
	cnt_a = table->reverse_count_a;
	cnt_b = table->reverse_count_b;
	if (cnt_a > 0 && cnt_b > 0 && is_rrr(table))
		rrr(table);
	else if (cnt_a > 0 && is_rra(table))
		rra(table);
	else if (cnt_b > 0 && is_rrb(table))
		rrb(table);
	else
		return (false);
	return (true);
}
