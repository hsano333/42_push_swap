/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_three_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:57:45 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 02:59:45 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_or_three_node.h"
#include "libft_str.h"
#include "push_swap_util.h"
#include "deque_util.h"

static int	check_difference_id(t_deque *node)
{
	t_deque	*nil_node;
	size_t	i;
	size_t	id[5];	

	i = 0;
	while (i < 4)
		id[i++] = 0;
	nil_node = search_nil(node);
	node = nil_node->next;
	i = 0;
	while (node->content != NULL)
	{
		id[i] = node->content->id;
		node = node->next;
		if (i >= 4)
			break ;
		i++;
	}
	if ((id[3] != id[2]) || (id[2] != id[1]))
		return (true);
	return (false);
}

int	is_two_or_three_node(t_abtable *table)
{
	t_deque	*a_node;
	t_deque	*b_node;
	size_t	a_id;
	size_t	b_id;
	size_t	cnt;

	a_node = search_nil(table->a)->next;
	b_node = search_nil(table->b)->next;
	a_id = 0;
	b_id = 0;
	cnt = 0;
	cnt = count_node(a_node, 0);
	if ((2 <= cnt && cnt <= 3) || check_difference_id(a_node))
		return (true);
	cnt = count_node(b_node, 0);
	if (!can_sort(table, A_TABLE) && (cnt == 2 || check_difference_id(b_node)))
		return (true);
	return (false);
}

static void	loop_execute_inst(t_abtable *table, char **split_c, \
		char **split_i, char target)
{
	int		i;
	int		c;
	size_t	len_c;

	i = 0;
	c = 0;
	while (split_i[i])
	{
		len_c = ft_strlen(split_c[c]);
		if (split_c[c] && !ft_strncmp(split_i[i], split_c[c], len_c))
		{
			execute_str_both_inst_wrapper(table, split_i[i]);
			c++;
		}
		else
			execute_str_inst_wrapper(table, split_i[i], target);
		i++;
	}
}

void	execute_inst(t_abtable *table, char *common, char *mono, char target)
{
	char	**split_c;
	char	**split_i;

	split_c = ft_split(common, ' ');
	split_i = ft_split(mono, ' ');
	if (!split_c || !split_i)
	{
		ft_free_split(split_c);
		ft_free_split(split_i);
		kill_process(table);
	}
	loop_execute_inst(table, split_c, split_i, target);
	ft_free_split(split_c);
	ft_free_split(split_i);
}

void	two_or_three_node(t_abtable *table)
{
	int		len_a;
	int		len_b;
	char	*inst_a;
	char	*inst_b;

	inst_a = two_or_three_node_a(table);
	inst_b = two_or_three_node_b(table);
	len_a = (int)ft_strlen(inst_a);
	len_b = (int)ft_strlen(inst_b);
	if (len_a > len_b)
		execute_inst(table, inst_b, inst_a, A_TABLE);
	else
		execute_inst(table, inst_a, inst_b, B_TABLE);
}
