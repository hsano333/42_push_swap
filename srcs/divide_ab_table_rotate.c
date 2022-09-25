/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab_table_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:01:34 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 04:07:28 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

static void	execute_rotate_a_force(t_abtable *table)
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

static void	execute_rotate_a(t_abtable *table, int force)
{
	if (force == true)
		execute_rotate_a_force(table);
	else
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
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
}

static void	execute_rotate_b_force(t_abtable *table)
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

static void	execute_rotate_b(t_abtable *table, int force)
{
	if (force == true)
		execute_rotate_b_force(table);
	else
	{
		if (table->ra_flag && table->rb_flag)
		{
			rr(table);
			table->ra_flag = false;
			table->reverse_count_a++;
			table->reverse_count_b++;
		}
		else if (table->rb_flag)
		{
			rb(table);
			table->reverse_count_b++;
		}
		else
			table->rb_flag = true;
	}
}

void	execute_rotate(t_abtable *table, char target, int force, int final)
{
	if (final == true)
	{
		if (target == A_TABLE && table->first_flag && table->rb_flag)
			rb(table);
		table->ra_flag = false;
		table->rb_flag = false;
	}
	else if (target == A_TABLE)
		execute_rotate_a(table, force);
	else if (target == B_TABLE)
		execute_rotate_b(table, force);
}
