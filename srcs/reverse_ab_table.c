/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ab_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:34:17 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:30:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "deque.h"

void	rra(t_abtable *table)
{
	shift_down(table->a);
}

void	rrb(t_abtable *table)
{
	shift_down(table->b);
}

void	rrr(t_abtable *table)
{
	rra(table);
	rrb(table);
}
