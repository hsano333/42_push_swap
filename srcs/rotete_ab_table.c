/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotete_ab_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:33:14 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 14:50:47 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "deque.h"

void	ra(t_abtable *table)
{
	shift_up(table->a);
	if (table->put_flag)
		ft_printf("ra\n");
}

void	rb(t_abtable *table)
{
	shift_up(table->b);
	if (table->put_flag)
		ft_printf("rb\n");
}

void	rr(t_abtable *table)
{
	int	tmp_flag;

	tmp_flag = table->put_flag;
	table->put_flag = false;
	ra(table);
	rb(table);
	if (tmp_flag)
		ft_printf("rr\n");
	table->put_flag = tmp_flag;
}


