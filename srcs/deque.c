/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:07:59 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 16:55:38 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*init_deque(void)
{
	t_deque	*node;

	node = (t_deque *)malloc(sizeof(t_deque));
	if (!node)
		return (NULL);
	node->content = NULL;
	node->prev = node;
	node->next = node;
	return (node);
}

t_deque	*search_nil(t_deque *node)
{
	while (node->content != NULL)
		node = node->next;
	return (node);
}

int	is_empty(t_deque *node)
{
	t_deque	*nil_node;

	nil_node = search_nil(node);
	if (nil_node->next == nil_node->prev)
		return (true);
	return (false);
}

int	add_back(t_deque *src_node, void *content)
{
	t_deque	*node;
	t_deque	*nil_node;
	t_deque	*tmp_node;

	if (content == NULL)
		return (false);
	nil_node = search_nil(src_node);
	node = (t_deque *)malloc(sizeof(t_deque));
	if (!node)
		return (false);
	node->content = content;
	tmp_node = nil_node->prev;
	node->prev = tmp_node;
	node->next = nil_node;
	tmp_node->next = node;
	nil_node->prev = node;
	return (true);
}

int	add_front(t_deque *src_node, void *content)
{
	t_deque	*node;
	t_deque	*nil_node;
	t_deque	*tmp_node;

	if (content == NULL)
		return (false);
	nil_node = search_nil(src_node);
	node = (t_deque *)malloc(sizeof(t_deque));
	if (!node)
		return (false);
	node->content = content;
	tmp_node = nil_node->next;
	node->prev = nil_node;
	node->next = tmp_node;
	nil_node->next = node;
	tmp_node->prev = node;
	return (true);
}
