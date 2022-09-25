/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:27:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 16:02:53 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table_util.h"
#include "can_command.h"
#include "libft_str.h"

int	get_node_id(t_deque *node)
{
	if (node->content == NULL)
		return (0);
	return (node->content->id);
}

static void	reverse_loop(t_abtable *table)
{
	int	a_flag;
	int	b_flag;

	while (table->first_flag == false)
	{
		a_flag = (id_is_more_than_one(table->a) \
					&& ((table->reverse_count_a > 0) || is_rra(table)));
		b_flag = ((id_is_more_than_one(table->b)) \
					&& ((table->reverse_count_b > 0) || is_rrb(table)));
		if (a_flag)
			table->reverse_count_a--;
		if (b_flag)
			table->reverse_count_b--;
		if (a_flag && b_flag)
			rrr(table);
		else if (a_flag)
			rra(table);
		else if (b_flag)
			rrb(table);
		else
			break ;
	}
}

void	rotation_for_reverse(t_abtable *table)
{
	if (id_is_more_than_one(table->a) == false)
		table->reverse_count_a = 0;
	if (id_is_more_than_one(table->b) == false)
		table->reverse_count_b = 0;
	reverse_loop(table);
	table->reverse_count_a = 0;
	table->reverse_count_b = 0;
	table->first_flag = false;
}

void	init_flag(t_abtable *table, char target)
{
	if (target == A_TABLE)
	{
		table->reverse_count_a = 0;
		table->ra_flag = false;
	}
	else if (target == B_TABLE)
	{
		table->reverse_count_b = 0;
		table->rb_flag = false;
	}
	else
	{
		table->reverse_count_a = 0;
		table->reverse_count_b = 0;
		table->ra_flag = false;
		table->rb_flag = false;
	}
}

char	*get_common_instruction(char *inst_a, char *inst_b, \
												int len_a, int len_b)
{
	char	*common;
	int		i;

	i = -1;
	common = NULL;
	if (len_a == len_b)
		common = inst_a;
	else if (len_a > len_b)
	{
		while (++i < len_a)
		{
			if (ft_strnstr(&(inst_a[i]), inst_b, len_b))
				common = &(inst_a[i]);
		}
	}
	else
	{
		while (++i < len_b)
		{
			if (ft_strnstr(&(inst_b[i]), inst_a, len_a))
				common = &(inst_b[i]);
		}
	}
	return (common);
}
