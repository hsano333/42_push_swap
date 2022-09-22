/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab_table_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:57:03 by hsano             #+#    #+#             */
/*   Updated: 2022/09/23 03:09:04 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

void	execute_shift(t_abtable *table, char target, t_pivot pivot)
{
	//printf("target =%d, pivot=%zu\n", target, pivot.middle);
	if (is_ss(table))
		ss(table);
	else if (is_sb(table, target, pivot))
		sb(table);
	else if (is_sa(table, target, pivot))
		sa(table);
	//printf("end execute_shift No.1\n");
}

void	execute_reverse(t_abtable *table)
{
	if (is_rrr(table))
		rrr(table);
	else if (is_rra(table))
		rra(table);
	else if (is_rrb(table))
		rrb(table);
}

static void	execute_rotate_a(t_abtable *table, int force)
{
	if (table->rb_flag)
	{
		rr(table);
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else if (force == true)
	{
		if (table->ra_flag)
			ra(table);
		table->ra_flag = false;
	}
	else if (table->ra_flag)
	{
		ra(table);
		table->ra_flag = false;
	}
	else 
		table->ra_flag = true;
}

static void	execute_rotate_b(t_abtable *table, int force)
{
	if (table->ra_flag)
	{
		rr(table);
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else if (force == true)
	{
		if (table->rb_flag)
			rb(table);
		table->rb_flag = false;
	}
	else if (table->rb_flag)
	{
		rb(table);
		table->rb_flag = false;
	}
	else
		table->rb_flag = true;

}

void	execute_rotate(t_abtable *table, char target, int force)
{
	if (target == A_TABLE)
		execute_rotate_a(table, force);
	else if (target == B_TABLE)
		execute_rotate_b(table, force);
	else if (target == BOTH_TABLE)
	{
		if (table->ra_flag && table->ra_flag)
			rr(table);
		else if (table->ra_flag)
			ra(table);
		else if (table->rb_flag)
			rb(table);
	}
}
