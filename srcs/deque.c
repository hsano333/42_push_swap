/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:07:59 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 15:28:02 by hsano            ###   ########.fr       */
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

#include <stdio.h>
#include "push_swap_util.h"
int	add_back(t_deque *src_node, void *content)
{
	t_deque	*node;
	t_deque	*nil_node;
	t_deque	*tmp_node;

	printf("test No.1\n");
	nil_node = search_nil(src_node);
	printf("test No.2\n");
	node = (t_deque *)malloc(sizeof(t_deque));
	printf("test No.3\n");
	if (!node)
		return (false);
	printf("test No.4\n");
	node->content = content;
	tmp_node = nil_node->prev;
	node->prev = tmp_node;
	node->next = nil_node;
	tmp_node->next = node;
	nil_node->prev = node;
	printf("test No.5\n");


	t_compre	*compre;

	printf("test No.6\n");
	compre = content;
	if (content == NULL)
		printf("NULL\n");
	printf("test No.7\n");
	printf("add test compre:origin=%d, compre=%zu\n ", compre->origin, compre->compre);
	printf("test No.8\n");

	return (true);
}

int	add_front(t_deque *src_node, void *content)
{
	t_deque	*node;
	t_deque	*nil_node;
	t_deque	*tmp_node;

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
