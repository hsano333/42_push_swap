/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:21:15 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:30:51 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void*	pop_front(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*front_node;
	void	*tmp_content;

	if (!src_node)
		return (NULL);
	nil_node = search_nil(src_node);
	front_node = (t_deque *)(nil_node->next);
	tmp_content = front_node->content;
	if (tmp_content == NULL)
		return (NULL);
	((t_deque *)front_node->next)->prev = nil_node;
	nil_node->next = front_node->next;
	free(front_node);
	return (tmp_content);
}

void*	pop_back(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*back_node;
	void	*tmp_content;

	if (!src_node)
		return (NULL);
	nil_node = search_nil(src_node);
	back_node = (t_deque *)(nil_node->prev);
	if (back_node->content == NULL)
		return (NULL);
	tmp_content = back_node->content;
	((t_deque *)back_node->prev)->next = nil_node;
	nil_node->prev = back_node->prev;
	free(back_node);
	return (tmp_content);
}
