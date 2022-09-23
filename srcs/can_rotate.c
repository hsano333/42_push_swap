/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:01:33 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 02:42:49 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

static size_t	*get_val(t_abtable *table, size_t *val, char target)
{
	t_deque	*nil_a;
	t_deque	*nil_b;

	nil_a = search_nil(table->a);
	nil_b = search_nil(table->b);
	//printf("get_val test No.1\n");
	if ((target != B_TABLE) \
		&& (nil_a->next == nil_a || (nil_a->prev == nil_a)))
	   	//|| equal_id(nil_a->next, nil_a->prev) == false)))
		return (NULL);
	//printf("get_val test No.2\n");
	if ((target != A_TABLE) \
		&& (nil_b->next == nil_b || (nil_b->prev == nil_b)))
	   	//|| equal_id(nil_b->next, nil_b->prev) == false)))
		return (NULL);
	//printf("get_val test No.3\n");
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
	//printf("target = , val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ", val[0], val[1], val[2], val[3]);
	if (val[0] >= val[1] && val[2] <= val[3])
		return (true);
	return (false);
}

int	is_rra(t_abtable *table)
{
	size_t	val[5];

	//if (!id_is_more_than_one(table->a))
		//reutrn (false);
	if (get_val(table, val, A_TABLE) == NULL)
		return (false);
	//if (target == B_TABLE && get_val(table, val, BOTH_TABLE) == NULL)
		//return (false);
	//else if (target == BOTH_TABLE && get_val(table, val, A_TABLE) == NULL)
		//return (false);
	//printf("rotate target = , val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ", val[0], val[1], val[2], val[3]);
	if (val[0] <= val[1])
	{
		//printf("is rra true No.1\n");
		return (true);
	}
	return (false);
}

int	is_rrb(t_abtable *table)
{
	size_t	val[5];

	//jif (!id_is_more_than_one(table->b))
		//jreutrn (false);
	if (get_val(table, val, B_TABLE) == NULL)
		return (false);
	//printf("rotate = , val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ", val[0], val[1], val[2], val[3]);
	if (val[2] <= val[3])
	{
		//printf("is rrb true No.2\n");
		return (true);
	}
		//printf("is sb false No.3\n");
	return (false);
}
