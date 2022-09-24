/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:01:33 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 02:37:17 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

static size_t	*get_val(t_abtable *table, size_t *val, char target)
{
	t_deque	*nil_a;
	t_deque	*nil_b;

	nil_a = search_nil(table->a);
	nil_b = search_nil(table->b);
	if ((target != B_TABLE) \
		&& (nil_a->next == nil_a || (nil_a->prev == nil_a)))
		return (NULL);
	if ((target != A_TABLE) \
		&& (nil_b->next == nil_b || (nil_b->prev == nil_b)))
		return (NULL);
	if ((target == A_TABLE) || (target == BOTH_TABLE))
	{
		val[0] = ((t_deque *)nil_a->next)->content->id;
		val[1] = ((t_deque *)nil_a->prev)->content->id;
	}
	if (target == B_TABLE || target == BOTH_TABLE)
	{
		val[2] = ((t_deque *)nil_b->next)->content->id;
		val[3] = ((t_deque *)nil_b->prev)->content->id;
	}
	return (val);
}

int	is_rrr(t_abtable *table)
{
	t_deque	*nil_a;
	size_t	val[5];

	if (!id_is_more_than_one(table->a) || !id_is_more_than_one(table->b))
		return (false);
	nil_a = search_nil(table->a);
	if (get_val(table, val, BOTH_TABLE) == NULL)
		return (false);
	if (val[0] >= val[1] && val[2] <= val[3])
		return (true);
	return (false);
}

int	is_rra(t_abtable *table)
{
	size_t	val[5];

	if (get_val(table, val, A_TABLE) == NULL)
		return (false);
	if (val[0] <= val[1])
		return (true);
	return (false);
}

int	is_rrb(t_abtable *table)
{
	size_t	val[5];

	if (get_val(table, val, B_TABLE) == NULL)
		return (false);
	if (val[2] <= val[3])
	{
		return (true);
	}
	return (false);
}
