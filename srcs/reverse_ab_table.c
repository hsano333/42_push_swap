/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ab_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:34:17 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 14:43:13 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"

void	rra(t_abtable *table)
{
	shift_down(table->a);
	if (table->put_flag)
		ft_printf("rra\n");
}

void	rrb(t_abtable *table)
{
	shift_down(table->b);
	if (table->put_flag)
		ft_printf("rrb\n");
}

void	rrr(t_abtable *table)
{
	int	tmp_flag;

	tmp_flag = table->put_flag;
	table->put_flag = false;
	rra(table);
	rrb(table);
	if (tmp_flag)
		ft_printf("rrr\n");
	table->put_flag = tmp_flag;
}
