/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:42:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 16:32:04 by hsano            ###   ########.fr       */
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
		ft_printf("contents: origin=%d, compre=%d\n", val->origin, val->compre);
	}
}
