/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:00:28 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:30:56 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	swap_deque(t_deque *src_node)
{
	t_deque	*nil_node;
	t_deque	*first_node;

	if (!src_node)
		return ;
	nil_node = search_nil(src_node);
}


