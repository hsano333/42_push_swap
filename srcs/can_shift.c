/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:16:45 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 02:38:21 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "can_command.h"

static size_t	*get_val(t_abtable *table, size_t *val, char target)
{
	t_deque	*nil_a;
	t_deque	*nil_b;

	nil_a = search_nil(table->a);
	nil_b = search_nil(table->b);
	if ((target != B_TABLE) && ((count_node(nil_a, 0) >= 3) \
		|| (nil_a->next == nil_a) || ((t_deque *)nil_a->next)->next == nil_a \
	   	|| equal_id(nil_a->next,((t_deque *)nil_a->next)->next) == false))
		return (NULL);
	if ((target != A_TABLE) && ((count_node(nil_a, 0) >= 3) \
		|| (nil_b->next == nil_b) || ((t_deque *)nil_b->next)->next == nil_b
	   	|| equal_id(nil_b->next,((t_deque *)nil_b->next)->next) == false))
		return (NULL);
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
	return (val);
}

int	is_ss(t_abtable *table, t_pivot pivot)
{
	t_deque	*nil_a;
	size_t	val[5];

	nil_a = search_nil(table->a);
	if (get_val(table, val, BOTH_TABLE) == NULL)
		return (false);
	if (val[0] > val[1] && val[2] < val[3]
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large)) \
		&& ((val[2] >= pivot.large && val[3] >= pivot.large) || (val[2] < pivot.large && val[3] < pivot.large)))
		return (true);
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
	if ((target == A_TABLE || target == BOTH_TABLE) && (val[0] > val[1] \
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large))))
	{
		return (true);
	}
	else if ((target == B_TABLE) && (val[3] > pivot.small) && (val[0] > val[1]) \
		&& ((val[0] >= pivot.large && val[1] >= pivot.large) || (val[0] < pivot.large && val[1] < pivot.large)))
	{
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
	if ((target == A_TABLE) && (val[2] < val[3]) && (val[1] <= pivot.large) \
		&& ((val[2] > pivot.large && val[3] > pivot.large) || (val[2] <= pivot.large && val[3] <= pivot.large)))
	{
		return (true);
	}
	else if ((target == B_TABLE || (target == BOTH_TABLE)) && (val[2] < val[3])
		&& ((val[2] > pivot.large && val[3] > pivot.large) || (val[2] <= pivot.large && val[3] <= pivot.large)))
	{
		return (true);
	}
	return (false);
}
