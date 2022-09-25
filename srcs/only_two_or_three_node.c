/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_two_or_three_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:13:23 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 15:47:13 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_or_three_node.h"
#include "libft_str.h"

#include <stdio.h>
int	is_only_two_or_three_node_in_table(t_deque *node)
{
	size_t	cnt;

	cnt = count_node(node, 0);
	if (2 <= cnt && cnt <= 3)
		return (true);
	return (false);
}

static char *only_two_or_three_node_inst_a(char *numbers)
{
	if (!ft_strncmp(numbers, "ACB", 3))
		return (INSTRUCTIONS_CAD);
	else if (!ft_strncmp(numbers, "BAC", 3))
		return (INSTRUCTIONS_A);
	else if (!ft_strncmp(numbers, "BCA", 3))
		return (INSTRUCTIONS_D);
	else if (!ft_strncmp(numbers, "CAB", 3))
		return (INSTRUCTIONS_C);
	else if (!ft_strncmp(numbers, "CBA", 3))
		return (INSTRUCTIONS_AD);
	else if (!ft_strncmp(numbers, "BA", 2))
		return (INSTRUCTIONS_A);
	return ("");
}

static char *only_two_or_three_node_inst_b(char *numbers)
{
	if (!ft_strncmp(numbers, "CAB", 3))
		return (INSTRUCTIONS_CAD);
	else if (!ft_strncmp(numbers, "BCA", 3))
		return (INSTRUCTIONS_A);
	else if (!ft_strncmp(numbers, "BAC", 3))
		return (INSTRUCTIONS_D);
	else if (!ft_strncmp(numbers, "ACB", 3))
		return (INSTRUCTIONS_C);
	else if (!ft_strncmp(numbers, "ABC", 3))
		return (INSTRUCTIONS_AD);
	else if (!ft_strncmp(numbers, "AB", 2))
		return (INSTRUCTIONS_A);
	return ("");
}

char	*only_two_or_three_node_inst(char target, char *numbers)
{

	if (target == A_TABLE)
		return (only_two_or_three_node_inst_a(numbers));
	else if (target == B_TABLE)
		return (only_two_or_three_node_inst_b(numbers));
	return (NULL);
}

