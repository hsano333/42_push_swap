/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:27:04 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 16:10:02 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table_util.h"
#include "can_command.h"
#include "libft_str.h"

int	get_node_id(t_deque *node)
{
	if (node->content == NULL)
		return (0);
	return (node->content->id);

}

/*
t_deque	*countup_table_id(t_abtable *table, char target)
{
	t_deque	*node;

	if (target == A_TABLE)
	{
		node = table->a;
		table->b_no += 2;
	}
	else
	{
		node = table->b;
		table->a_no += 2;
	}
	return (node);
}
*/

void	rotation_for_reverse(t_abtable *table)
{
	int	a_flag;
	int	b_flag;



	printf("rotation for reverse No.1  a=%d, b=%d\n",table->reverse_count_a,table->reverse_count_b  );
	if (id_is_more_than_one(table->a) == false)
		table->reverse_count_a = 0;
	printf("rotation for reverse No.2  a=%d, b=%d\n",table->reverse_count_a,table->reverse_count_b  );
	if (id_is_more_than_one(table->b) == false)
		table->reverse_count_b = 0;
	printf("rotation for reverse No.3  a=%d, b=%d\n",table->reverse_count_a,table->reverse_count_b  );
	printf("rotation for reverse No.4 is_rra=%d, is_rrb=%d,  \n", is_rra(table), is_rra(table));
	while (1)
	{
		a_flag = id_is_more_than_one(table->a) && ((table->reverse_count_a > 0 || is_rra(table)));
		b_flag = id_is_more_than_one(table->b) && ((table->reverse_count_b > 0 || is_rrb(table)));
		if (a_flag && b_flag && is_rra(table))
		{
			rrr(table);
			table->reverse_count_a--;
			table->reverse_count_b--;
		}
		else if (a_flag)
		{
			rra(table);
			table->reverse_count_a--;
		}
		else if (b_flag)
		{
			rrb(table);
			table->reverse_count_b--;
		}
		else
			break ;
	}
}

void	init_flag(t_abtable *table, char target)
{
	if (target == A_TABLE)
	{
		table->reverse_count_a = 0;
		table->ra_flag = false;
	}
	else if (target == B_TABLE)
	{
		table->reverse_count_b = 0;
		table->rb_flag = false;
	}
	else
	{
		table->reverse_count_a = 0;
		table->reverse_count_b = 0;
		table->ra_flag = false;
		table->rb_flag = false;
	}
}

char	*get_common_instruction(char *inst_a, char *inst_b, size_t len_a, size_t len_b)
{
	char	*common;
	size_t		i;

	i = 0;
	if (len_a == len_b)
		common = inst_a;
	else if (len_a > len_b)
	{
		while (i++ < len_a)
		{
			if (ft_strnstr(&(inst_a[i]), inst_b, len_b))
				common = &(inst_a[i]);
		}
	}
	else
	{
		while (i++ < len_b)
		{
			if (ft_strnstr(&(inst_b[i]), inst_a, len_a))
				common = &(inst_b[i]);
		}
	}
	return (common);
}
