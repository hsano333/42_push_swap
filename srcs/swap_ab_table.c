/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:48 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 14:47:00 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"

void	sa(t_abtable *table)
{
	swap(table->a);
	if (table->put_flag)
		ft_printf("sa\n");
}


void	sb(t_abtable *table)
{
	swap(table->b);
	if (table->put_flag)
		ft_printf("sb\n");
}

void	ss(t_abtable *table)
{
	int	tmp_flag;

	tmp_flag = table->put_flag;
	table->put_flag = false;
	sa(table);
	sb(table);
	if (tmp_flag)
		ft_printf("ss\n");
	table->put_flag = tmp_flag;
}

void	pa(t_abtable *table)
{
	t_compre	*val;

	val = pop_front(table->b);
	push_front(table->a, val);
	if (table->put_flag)
		ft_printf("pa\n");
}

void	pb(t_abtable *table)
{
	t_compre	*val;

	val = pop_front(table->a);
	push_front(table->b, val);
	if (table->put_flag)
		ft_printf("pb\n");
}
