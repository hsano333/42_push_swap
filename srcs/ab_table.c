/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:47:51 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 16:43:02 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ab_table.h"
#include "deque.h"
#include "ft_printf.h"

t_abtable	*create_ab_table(t_deque *a, t_deque *b, int put_flag)
{
	t_abtable	*table;

	if (!a || !b)
	{
		free(a);
		free(b);
		return (NULL);
	}
	table = (t_abtable *)malloc(sizeof(t_abtable));
	table->a = a;
	table->b = b;
	table->no = 0;
	table->first_flag = true;
	table->reverse_count_a = 0;
	table->reverse_count_b = 0;
	table->ra_flag = false;
	table->rb_flag = false;
	table->put_flag = put_flag;
	return (table);
}

void	clear_ab_table(t_abtable *table)
{
	clear_deque(table->a);
	clear_deque(table->b);
	free(table);
}

void	put_table(t_abtable *table)
{
	ft_printf("table A\n");
	put_all(table->a);
	ft_printf("\ntable B\n");
	put_all(table->b);
	ft_printf("put table end\n");
}
