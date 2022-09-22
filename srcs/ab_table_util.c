/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:27:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/21 15:33:50 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table_util.h"

int	get_node_id(t_deque *node)
{
	if (node->content == NULL)
		return (0);
	return (node->content->id);

}
