/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:01 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 18:43:43 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	swap(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*first_node;
	t_deque	*second_node;

	if (!src_node || count_node(src_node) < 2)
		return ;
	nil_node = search_nil(src_node);
	first_node = nil_node->next;
	second_node = first_node->next;
	nil_node->next = second_node;
	second_node->prev = nil_node;
	first_node->next = second_node->next;
	((t_deque *)second_node->next)->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
}

void	shift_up(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*first_node;
	size_t	len;

	if (!src_node)
		return ;
	nil_node = search_nil(src_node);
	first_node = nil_node->next;
	len = count_node(src_node);
	if (len < 2)
		return ;
	else if (len == 2)
		return (swap(src_node));
	nil_node->next = first_node->next;
	((t_deque *)first_node->next)->prev = nil_node;
	((t_deque *)nil_node->prev)->next = first_node;
	first_node->prev = nil_node->prev;
	first_node->next = nil_node;
	nil_node->prev = first_node;
}

void	shift_down(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*last_node;
	size_t	len;

	if (!src_node)
		return ;
	nil_node = search_nil(src_node);
	last_node = nil_node->prev;
	len = count_node(src_node);
	if (len < 2)
		return ;
	else if (len == 2)
		return (swap(src_node));
	((t_deque *)last_node->prev)->next = nil_node;
	nil_node->prev = last_node->prev;
	last_node->prev = nil_node;
	last_node->next = nil_node->next;
	((t_deque *)nil_node->next)->prev = last_node;
	nil_node->next = last_node;
}
