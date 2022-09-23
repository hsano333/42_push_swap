/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab_table_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:57:03 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 01:50:43 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

t_deque	*execute_shift(t_abtable *table, char target, t_pivot pivot, t_deque *node)
{
	t_deque	*nil_node;
	//printf("target =%d, pivot=%zu\n", target, pivot.middle);
	if (table->ra_flag == true || table->rb_flag == true)
		return node;
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
	//printf("end execute_shift No.1\n");
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
	//printf("execute_reverse test No.1 cnt_a=%d, b=%d\n", cnt_a, cnt_b);
	//if (table->reverse_count_a == 0 && table->reverse_count_a == 0)
		//return (false);
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

static void	execute_rotate_a(t_abtable *table, int force)
{
	if (force == true)
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
			table->reverse_count_a++;
			table->reverse_count_b++;
		}
		else if (table->ra_flag)
		{
			ra(table);
			table->reverse_count_a++;
		}
		else if (table->rb_flag)
		{
			rb(table);
			table->reverse_count_b++;
		}
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
			//table->ra_flag = false;
			table->rb_flag = false;
			table->reverse_count_a++;
			table->reverse_count_b++;
		}
		else if (table->ra_flag)
		{
			ra(table);
			table->reverse_count_a++;
		}
		else
			table->ra_flag = true;
	}
	/*
	if (table->rb_flag && force == false)
	{
		rr(table);
		table->ra_flag = false;
		table->rb_flag = false;
		table->reverse_count_a++;
		table->reverse_count_b++;
	}
	else if (force == true && table->ra_flag)
	{
		table->reverse_count_a++;
		ra(table);
		table->ra_flag = false;
	}
	else if (force == true && table->rb_flag)
	{
		table->reverse_count_b++;
		rb(table);
		table->rb_flag = false;

	}
	else if (force == true)
	{
		table->ra_flag = false;
	}
	else if (table->ra_flag)
	{
		ra(table);
		table->reverse_count_a++;
		//table->ra_flag = false;
	}
	else 
		table->ra_flag = true;
		*/
}

static void	execute_rotate_b(t_abtable *table, int force)
{

	if (force == true)
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
			table->reverse_count_a++;
			table->reverse_count_b++;
		}
		else if (table->ra_flag)
		{
			ra(table);
			table->reverse_count_a++;
		}
		else if (table->rb_flag)
		{
			rb(table);
			table->reverse_count_b++;
		}
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
			table->ra_flag = false;
			table->reverse_count_a++;
			table->reverse_count_b++;
			//table->rb_flag = false;
		}
		else if (table->rb_flag)
		{
			rb(table);
			table->reverse_count_b++;
		}
		else
			table->rb_flag = true;
	}


	/*
	if (table->ra_flag && force == false)
	{
		rr(table);
		table->ra_flag = false;
		table->rb_flag = false;
		table->reverse_count_a++;
		table->reverse_count_b++;
	}
	else if (force == true && table->rb_flag)
	{
		rb(table);
		table->reverse_count_b++;
		table->rb_flag = false;
	}
	else if (force == true && table->ra_flag)
	{
		ra(table);
		table->reverse_count_a++;
		table->ra_flag = false;

	}
	else if (force == true)
	{
		table->rb_flag = false;
	}
	else if (table->rb_flag)
	{
		rb(table);
		table->reverse_count_b++;
		//table->rb_flag = false;
	}
	else
		table->rb_flag = true;
		*/

}

void	execute_rotate(t_abtable *table, char target, int force, int final)
{
	if (final == true)
	{
		if (target == A_TABLE && table->ra_flag)
			ra(table);
		else if (target == B_TABLE && table->rb_flag)
			rb(table);
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else if (target == A_TABLE)
		execute_rotate_a(table, force);
	else if (target == B_TABLE)
		execute_rotate_b(table, force);
}
