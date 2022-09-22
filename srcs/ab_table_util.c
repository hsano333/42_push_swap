/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:27:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 22:19:08 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table_util.h"

int	get_node_id(t_deque *node)
{
	if (node->content == NULL)
		return (0);
	return (node->content->id);

}

t_deque	*countup_table_id(t_abtable *table, char target)
{
	t_deque	*node;

	if (target == A_TABLE)
	{
		node = table->a;
		table->b_no += 2;
	}
	else
	{
		node = table->b;
		table->a_no += 2;
	}
	return (node);
}

void	rotation_for_reverse(t_abtable *table)
{
	while (1)
	{
		if (table->reverse_count_a > 0 && table->reverse_count_b > 0)
		{
			rrr(table);
			table->reverse_count_a--;
			table->reverse_count_b--;
		}
		else if (table->reverse_count_a > 0)
		{
			rra(table);
			table->reverse_count_a--;
		}
		else if (table->reverse_count_b > 0)
		{
			rrb(table);
			table->reverse_count_b--;
		}
		else
			break ;
	}
}

int	is_less_than_four_table_a(t_abtable *table)
{
	t_deque	*node;
	t_deque	*nil_node;
	int		id;

	node = table->a;
	nil_node = search_nil(node);
	node = nil_node->next;
	if (node == nil_node)
		return (false);
	id = node->content->id;
	return (true);
}
