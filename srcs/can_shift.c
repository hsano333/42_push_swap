/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:16:45 by hsano             #+#    #+#             */
/*   Updated: 2022/09/23 19:25:33 by hsano            ###   ########.fr       */
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
	if ((target != B_TABLE) && ((count_node(nil_a, 0) >= 3) \
		|| (nil_a->next == nil_a) || ((t_deque *)nil_a->next)->next == nil_a \
	   	|| equal_id(nil_a->next,((t_deque *)nil_a->next)->next) == false))
		return (NULL);
	//printf("get_val test No.2\n");
	if ((target != A_TABLE) && ((count_node(nil_a, 0) >= 3) \
		|| (nil_b->next == nil_b) || ((t_deque *)nil_b->next)->next == nil_b
	   	|| equal_id(nil_b->next,((t_deque *)nil_b->next)->next) == false))
		return (NULL);
	//printf("get_val test No.3\n");
	if (target == A_TABLE || target == BOTH_TABLE)
	{
		val[0] = ((t_deque *)nil_a->next)->content->compre;
		val[1] = ((t_deque *)(((t_deque *)nil_a->next)->next))->content->compre;
	}
	if (target == B_TABLE || target == BOTH_TABLE)
	{
		val[2] = ((t_deque *)nil_b->next)->content->compre;
		val[3] = ((t_deque *)(((t_deque *)nil_b->next)->next))->content->compre;
	}
	//if (target == BOTH_TABLE)
		//val[4] = ((t_deque *)nil_a->prev)->content->compre;
	return (val);
}

int	is_ss(t_abtable *table, t_pivot pivot)
{
	t_deque	*nil_a;
	size_t	val[5];

	nil_a = search_nil(table->a);
	if (get_val(table, val, BOTH_TABLE) == NULL)
		return (false);
	//printf("target = , val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ", val[0], val[1], val[2], val[3]);
	if (val[0] > val[1] && val[2] < val[3]
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large)) \
		&& ((val[2] >= pivot.large && val[3] >= pivot.large) || (val[2] < pivot.large && val[3] < pivot.large)))
		return (true);
	//else if (val[4] > val[0] && val[2] < val[3] && (equal_id(nil_a->next,nil_a->prev)))
	//{
		//rra(table);
		//return (true);
	//}
	return (false);
}

int	is_sa(t_abtable *table, char target, t_pivot pivot)
{
	size_t	val[5];

	if (target == A_TABLE && get_val(table, val, A_TABLE) == NULL)
		return (false);
	if (target == B_TABLE && get_val(table, val, BOTH_TABLE) == NULL)
		return (false);
	else if (target == BOTH_TABLE && get_val(table, val, A_TABLE) == NULL)
		return (false);
	//printf("target = %c, val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ",target,  val[0], val[1], val[2], val[3]);
	if ((target == A_TABLE || target == BOTH_TABLE) && (val[0] > val[1] \
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large))))
	{
		//printf("is sa true No.1\n");
		return (true);
	}
	else if ((target == B_TABLE) && (val[3] > pivot.small) && (val[0] > val[1]) \
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large)))
	{
		//printf("is sa true No.2\n");
		return (true);
	}
	return (false);
}

int	is_sb(t_abtable *table, char target, t_pivot pivot)
{
	size_t	val[5];

	if (target == A_TABLE && get_val(table, val, BOTH_TABLE) == NULL)
		return (false);
	else if (target == B_TABLE && get_val(table, val, B_TABLE) == NULL)
		return (false);
	else if (target == BOTH_TABLE && get_val(table, val, B_TABLE) == NULL)
		return (false);
	//printf("target = %c, val[0]=%zu, [1]=%zu,[2]=%zu, [3]=%zu\n ",target,  val[0], val[1], val[2], val[3]);
	if ((target == A_TABLE) && (val[2] < val[3]) && (val[1] <= pivot.large) \
		&& ((val[2] > pivot.large && val[3] > pivot.large) || (val[2] <= pivot.large && val[3] <= pivot.large)))
	{
		//printf("is sb true No.1\n");
		return (true);
	}
	else if ((target == B_TABLE || (target == BOTH_TABLE)) && (val[2] < val[3])
		&& ((val[2] > pivot.large && val[3] > pivot.large) || (val[2] <= pivot.large && val[3] <= pivot.large)))
	{
		//printf("is sb true No.2\n");
		return (true);
	}
		//printf("is sb false No.3\n");
	return (false);
}
