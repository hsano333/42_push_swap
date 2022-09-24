/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_three_node_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:56:28 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 00:31:57 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_or_three_node.h"
#include "libft_str.h"

static void	get_node_compre(t_deque *node, char *result)
{
	int		i;
	size_t	cnt;
	size_t	min;
	size_t	tmp[4];
	
	i = 3;
	while (i != -1)
		tmp[i--] = '\0';
	cnt = count_node(node, 0);
	i = -1;
	min = INT_MAX;
	while (++i < 3 && node->content != NULL)
	{
		tmp[i] = node->content->compre;
		if (min > node->content->compre)
			min = node->content->compre;
		node = node->next;
	}
	while (--i != -1)
	{
		if ((tmp[i] - min) < 5)
			result[i] = (int)(tmp[i] - min) + 'A';
		else
			result[i] = 'Z';

	}

	//while (--i != -1)
		//result[i] = (int)(tmp[i] - min) + 'A';
}

char	*two_or_three_node_a(t_abtable *table)
{
	t_deque	*node;
	size_t	id;
	char	result[4];

	id = 0;
	node = search_nil(table->a)->next;
	if (node->content == NULL)
		return (NULL);
	id = node->content->id;
	get_node_compre(node, result);
	if (!ft_strncmp(result, "ACB", 3 ))
		return INSTRUCTIONS_B;
	else if (!ft_strncmp(result, "BAC", 3 ))
		return INSTRUCTIONS_A;
	else if (!ft_strncmp(result, "BCA", 3 ))
		return INSTRUCTIONS_BA;
	else if (!ft_strncmp(result, "CAB", 3 ))
		return INSTRUCTIONS_AB;
	else if (!ft_strncmp(result, "CBA", 3 ))
		return INSTRUCTIONS_ABA;
	else if (!ft_strncmp(result, "BA", 2 ))
		return INSTRUCTIONS_A;
	return ("");
}

char	*two_or_three_node_b(t_abtable *table)
{
	t_deque	*node;
	size_t	id;
	char	result[8];

	id = 0;
	node = search_nil(table->b)->next;
	if (node->content == NULL)
		return (NULL);
	id = node->content->id;
	get_node_compre(node, result);
	if (!ft_strncmp(result, "CAB", 3 ))
		return INSTRUCTIONS_B;
	else if (!ft_strncmp(result, "BCA", 3 ))
		return INSTRUCTIONS_A;
	else if (!ft_strncmp(result, "BAC", 3 ))
		return INSTRUCTIONS_BA;
	else if (!ft_strncmp(result, "ACB", 3 ))
		return INSTRUCTIONS_AB;
	else if (!ft_strncmp(result, "ABC", 3 ))
		return INSTRUCTIONS_ABA;
	else if (!ft_strncmp(result, "AB", 2 ))
		return INSTRUCTIONS_A;
	return ("");
}

void	execute_str_both_instruction_wrapper(t_abtable *table, char *inst)
{
	if (!ft_strncmp(inst, "re", 2))
		execute_str_instruction(table, "rrr");
	else if (!ft_strncmp(inst, "s", 1))
		execute_str_instruction(table, "ss");
	else if (!ft_strncmp(inst, "r", 1))
		execute_str_instruction(table, "rr");
}

void	execute_str_instruction_wrapper(t_abtable *table, char *inst, char target)
{
	if (target == A_TABLE)
	{
		if (!ft_strncmp(inst, "s", 1))
		{
			execute_str_instruction(table, "sa");
		}
		else if (!ft_strncmp(inst, "re", 2))
		{
			execute_str_instruction(table, "rra");
		}
		else if (!ft_strncmp(inst, "r", 1))
		{
			execute_str_instruction(table, "ra");
		}
	}
	else if (target == B_TABLE)
	{
		if (!ft_strncmp(inst, "re", 2))
			execute_str_instruction(table, "rrb");
		else if (!ft_strncmp(inst, "s", 1))
			execute_str_instruction(table, "sb");
		else if (!ft_strncmp(inst, "r", 1))
			execute_str_instruction(table, "rb");
	}
}
