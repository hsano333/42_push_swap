/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotete_ab_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:33:14 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:30:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "deque.h"

void	ra(t_abtable *table)
{
	shift_up(table->a);
}

void	rb(t_abtable *table)
{
	shift_up(table->b);
}

void	rr(t_abtable *table)
{
	ra(table);
	rb(table);
}


