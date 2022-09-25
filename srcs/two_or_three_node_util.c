/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_three_node_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:56:28 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 15:43:51 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_or_three_node.h"
#include "libft_str.h"

static void	get_node_compre(t_deque *node, char *numbers)
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
			numbers[i] = (int)(tmp[i] - min) + 'A';
		else
			numbers[i] = 'Z';
	}
}

char	*two_or_three_node_a(t_abtable *table)
{
	t_deque	*node;
	size_t	id;
	char	numbers[4];

	id = 0;
	node = search_nil(table->a)->next;
	if (node->content == NULL)
		return ("");
	id = node->content->id;
	get_node_compre(node, numbers);
	if (is_only_two_or_three_node_in_table(table->a))
		return (only_two_or_three_node_inst(A_TABLE, numbers));
	else if (!ft_strncmp(numbers, "ACB", 3))
		return (INSTRUCTIONS_B);
	else if (!ft_strncmp(numbers, "BAC", 3))
		return (INSTRUCTIONS_A);
	else if (!ft_strncmp(numbers, "BCA", 3))
		return (INSTRUCTIONS_BA);
	else if (!ft_strncmp(numbers, "CAB", 3))
		return (INSTRUCTIONS_AB);
	else if (!ft_strncmp(numbers, "CBA", 3))
		return (INSTRUCTIONS_ABA);
	else if (!ft_strncmp(numbers, "BA", 2))
		return (INSTRUCTIONS_A);
	return ("");
}

char	*two_or_three_node_b(t_abtable *table)
{
	t_deque	*node;
	size_t	id;
	char	numbers[8];

	id = 0;
	node = search_nil(table->b)->next;
	if (node->content == NULL)
		return ("");
	id = node->content->id;
	get_node_compre(node, numbers);
	if (is_only_two_or_three_node_in_table(table->b))
		return (only_two_or_three_node_inst(B_TABLE, numbers));
	else if (!ft_strncmp(numbers, "CAB", 3))
		return (INSTRUCTIONS_B);
	else if (!ft_strncmp(numbers, "BCA", 3))
		return (INSTRUCTIONS_A);
	else if (!ft_strncmp(numbers, "BAC", 3))
		return (INSTRUCTIONS_BA);
	else if (!ft_strncmp(numbers, "ACB", 3))
		return (INSTRUCTIONS_AB);
	else if (!ft_strncmp(numbers, "ABC", 3))
		return (INSTRUCTIONS_ABA);
	else if (!ft_strncmp(numbers, "AB", 2))
		return (INSTRUCTIONS_A);
	return ("");
}

void	execute_str_both_inst_wrapper(t_abtable *table, char *inst)
{
	if (!ft_strncmp(inst, "re", 2))
		execute_str_instruction(table, "rrr");
	else if (!ft_strncmp(inst, "s", 1))
		execute_str_instruction(table, "ss");
	else if (!ft_strncmp(inst, "r", 1))
		execute_str_instruction(table, "rr");
}

void	execute_str_inst_wrapper(t_abtable *table, char *inst, char target)
{
	if (target == A_TABLE)
	{
		if (!ft_strncmp(inst, "re", 2))
			execute_str_instruction(table, "rra");
		else if (!ft_strncmp(inst, "s", 1))
			execute_str_instruction(table, "sa");
		else if (!ft_strncmp(inst, "r", 1))
			execute_str_instruction(table, "ra");
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
