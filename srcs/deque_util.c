/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:42:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 04:01:24 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "push_swap_init.h"
#include "ft_printf.h"

void	put_all(t_deque *node)
{
	t_deque		*nil_node;
	t_deque		*tmp_node;
	t_compre	*val;

	nil_node = search_nil(node);
	tmp_node = (t_deque *)nil_node->next;
	while (tmp_node->content != NULL)
	{
		val = tmp_node->content;
		tmp_node = (t_deque *)tmp_node->next;
		ft_printf("contents: origin=%d, compre=%d, id=%d, \n", val->origin, val->compre, val->id);
	}
}

size_t	count_node(t_deque *node)
{
	size_t	count;
	t_deque	*nil_node;
	t_deque	*tmp_node;

	if (node == NULL)
		return (0);
	nil_node = search_nil(node);
	tmp_node = nil_node->next;
	count = 0;
	while (tmp_node != nil_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	return (count);
}

int	equal_id(t_deque *a_node, t_deque *b_node)
{
	if (a_node->content == NULL || b_node->content)
		return (false);
	else if (a_node->content->id == b_node->content->id)
		return (true);
	return (false);
}

void	update_id(t_deque *node, int id)
{
	if (node->content == NULL)
		return ;
	node->content->id = id;
}
