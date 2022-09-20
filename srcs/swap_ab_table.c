/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:48 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:30:53 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "deque.h"

void	sa(t_abtable *table)
{
	swap(table->a);
}


void	sb(t_abtable *table)
{
	swap(table->b);
}

void	ss(t_abtable *table)
{
	sa(table);
	sb(table);
}

void	pa(t_abtable *table)
{
	void	*val;

	val = pop_front(table->b);
	push_front(table->a, val);
}

void	pb(t_abtable *table)
{
	void	*val;

	val = pop_front(table->a);
	push_front(table->b, val);

}
