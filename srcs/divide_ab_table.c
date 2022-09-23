/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:30:35 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 00:24:07 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "quick_sort.h"
#include "ab_table_util.h"
#include "can_command.h"
#include "push_swap_util.h"
#include <limits.h>
#include <stdio.h>

static t_pivot	calc_pivot(t_abtable *table, char target, int id)
{
	t_deque	*node;
	t_deque	*nil_node;
	size_t	max;
	size_t	min;
	t_pivot	pivot;

	min = INT_MAX;
	max = 0;
	node = table->b;
	if (target == A_TABLE)
		node = table->a;
	nil_node = search_nil(node);
	node = nil_node->next;
	while (node != nil_node)
	{
		if (max <= node->content->compre && id == node->content->id)
			max = node->content->compre;
		if (min > node->content->compre && id == node->content->id)
			min = node->content->compre;
		node = node->next;
	}
	pivot.small = (max - min) / 3 + min;
	pivot.middle = (max + min) / 2;
	pivot.large = max - (max - min) / 3;
	return (pivot);
}

static void	execute_table_a(t_abtable *table, t_deque *node, t_pivot pivot)
{
	size_t	tmp_compre;
	int		id;

	if (node->content->compre >= pivot.large)
	{
		update_id(node, table->b_no);
		//printf("execute_rotate a table No.1\n");
		execute_rotate(table, A_TABLE, false, false);
	}
	else if (node->content->compre < pivot.large)
	{
		tmp_compre = node->content->compre;
		id = node->content->id;
		update_id(node, table->b_no - 1);
		if (tmp_compre > pivot.small)
			update_id(node, table->b_no);
		//if (table->ra_flag || ((tmp_compre >= pivot.small) && (table->ra_flag || count_node(search_nil(table->b), id) >= 2)))
		//if (table->ra_flag || ((table->rb_flag) && (tmp_compre > pivot.small) && count_node(search_nil(table->b), id) >= 2))
		if (table->ra_flag || (table->rb_flag))
		{
			//printf("execute_rotate a table No.2\n");
			execute_rotate(table, B_TABLE, true, false);
		}
		pb(table);
		if ((tmp_compre > pivot.small) && (count_node(search_nil(table->b), id) >= 2))
		{
			//printf("execute_rotate a table No.3\n");
			execute_rotate(table, B_TABLE, false, false);
			//table->reverse_count_b++;
		}
	}
}



t_deque	*execute_divide_cmd(t_abtable *table, t_deque *node, char target, t_pivot pivot)
{
	size_t	tmp_compre;
	t_deque	*next_node;
	int		id;

	next_node = node->next;
	printf("target=%c, compre=%zu ,pivot, max=%zu, middle=%zu,min=%zu\n", target, node->content->compre, pivot.large, pivot.middle, pivot.small);
	if (target == A_TABLE)
		execute_table_a(table, node, pivot);
	else if(target == B_TABLE)
	{
		if (node->content->compre <= pivot.small)
		{
			update_id(node, table->a_no);
			execute_rotate(table, B_TABLE, false, false);
			//table->reverse_count_b++;
		}
		else if (node->content->compre > pivot.small)
		{
			tmp_compre = node->content->compre;
			id = node->content->id;
			update_id(node, table->a_no - 1);
			if (tmp_compre <= pivot.large)
				update_id(node, table->a_no);
			//if ((node->content->compre <= pivot.large) && (table->rb_flag || count_node(search_nil(table->b), id) >= 2))
			//if (table->rb_flag || ((table->ra_flag) && (tmp_compre <= pivot.large) && count_node(search_nil(table->b), id) >= 2))
			if (table->rb_flag || table->ra_flag)
			{
				execute_rotate(table, A_TABLE, true, false);
			}
			pa(table);
			if ((tmp_compre <= pivot.large) && (count_node(search_nil(table->b), id) >= 2))
			{
				//table->reverse_count_a++;
				execute_rotate(table, A_TABLE, false, false);
			}
		}
	}
	//node = node->next;
	next_node = execute_shift(table, target, pivot, next_node);
	return (next_node);
}


void	divide_ab_table(t_abtable *table, char target)
{
	int		id;
	t_pivot	pivot;
	t_deque	*node;
	t_deque	*nil_node;
	size_t	len;

	node = countup_table_id(table, target);
	nil_node = search_nil(node);
	node = nil_node->next;
	id = get_node_id(node);
	pivot = calc_pivot(table, target, id);
	len = count_node(node, id) + 1;
	//t_deque	*next_node;
	//while (len > 0 && node != nil_node && is_more_than_three(node, id))
	while (len > 0 && node != nil_node)
	{
		//next_node = ((t_deque *)node->next)->next;
		//printf("loop No.0 len =%zu\n", len);
		if (node->content->id == id && --len > 0)
		//{
			//printf("loop No.1\n");
			node = execute_divide_cmd(table, node, target, pivot);
		else
			break ;
			//node = nil_node->next;
			//node = nil_node->next;
		//}
		//else 
			//node = node->next;

		if (can_sort(table, target) == false)
		{
			printf("can_sort == false so escape loop and init()\n");
			init_flag(table, target);
			break ;
		}
	}
	if (node == nil_node)
		printf("node == nil_node , so escape loop\n");
	execute_rotate(table, target, false, true);
	execute_shift(table, BOTH_TABLE, pivot, node);
	rotation_for_reverse(table);
	//while (execute_reverse(table))
		//id++;
}