/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:44:12 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 16:56:28 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "ft_printf.h"
#include "push_swap_util.h"

void	kill_process(t_abtable *table)
{
	clear_ab_table(table);
	exit(EXIT_FAILURE);
}

int	can_sort(t_abtable *table, char target)
{
	t_deque	*nil_node;
	t_deque	*node;

	if (target == BOTH_TABLE && count_node(table->b, 0) > 0)
		return (true);
	//if (target == B_TABLE && can_sort(table, A_TABLE) == true)
		//return (false);
	nil_node = search_nil(table->a);
	node = nil_node->next;
	while (target != B_TABLE && node->next != nil_node)
	{
		//printf("can_sort No.1  now:%zu, next:%zu\n", node->content->compre, ((t_deque *)node->next)->content->compre);
		//printf("can_sort No.2  nil:%p, now:%p, next:%p\n", nil_node, node, node->next);
		if (node->content->compre + 1 != (((t_deque *)node->next)->content->compre))
			return (true);
		//printf("can_sort No.3  nil:%p, now:%p, next:%p\n", nil_node, node, node->next);
		node = node->next;
	}
	//printf("can sort No.2\n");
	nil_node = search_nil(table->b);
	node = nil_node->next;
	while (target == B_TABLE && node->next != nil_node)
	{
		if (node->content->compre != (((t_deque *)node->next)->content->compre + 1))
			return (true);
		node = node->next;
	}
	return (false);
}

void	reverse_a(t_abtable *table)
{
	t_deque		*nil_node_a;
	t_deque		*nil_node_b;
	t_deque		*node_b;
	size_t		base_val;
	size_t		next_val;

	//printf("reverse_a start\n");
	nil_node_a = search_nil(table->a);
	if (nil_node_a->next == nil_node_a)
		return ;
	base_val = ((t_deque *)nil_node_a->next)->content->compre;
	nil_node_b = search_nil(table->b);
	if (nil_node_b->next == nil_node_b)
		return ;
	node_b = nil_node_b->next;
	next_val = node_b->content->compre;
	while (base_val == next_val + 1)
	{
		pa(table);
		base_val = next_val;
		node_b = nil_node_b->next;
		if (node_b == nil_node_b)
			break ;
		next_val = node_b->content->compre;
	}
}

void	reverse_b(t_abtable *table)
{
	t_deque		*nil_node_a;
	t_deque		*nil_node_b;
	t_deque		*node_b;
	size_t		base_val;
	size_t		next_val;

	nil_node_a = search_nil(table->a);
	if (nil_node_a->next == nil_node_a)
		return ;
	base_val = ((t_deque *)nil_node_a->next)->content->compre;
	nil_node_b = search_nil(table->b);
	if (nil_node_b->next == nil_node_b)
		return ;
	node_b = nil_node_b->next;
	next_val = node_b->content->compre;
	while (base_val == next_val + 1)
	{
		pa(table);
		base_val = next_val;
		node_b = nil_node_b->next;
		if (node_b == nil_node_b)
			break ;
		next_val = node_b->content->compre;
	}
}


/*
void	convert_val_str(t_deque *node, int mode, int size)
{
	t_deque	*nil_node;
	t_deque	*tmp_node;
	size_t	order[100];
	int		i;
	int		min;

	nil_node = search_nil(node);
	tmp_node = nil_node->next;
	i = 0;
	min = INT_MAX;
	while (i < size)
	{
		if (min < tmp_node->content->compre)
			min = tmp_node->content->compre;
		order[i] = tmp_node->content->compre;
		tmp_node = tmp_node->next;
	}
}
*/
