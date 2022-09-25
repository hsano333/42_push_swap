/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:43:15 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 16:54:02 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "libft_str.h"

#include <stdio.h>
int	execute_str_instruction(t_abtable *table, char *inst)
{
	//printf("\ninst=%s, inst[0]=%d\n", inst, inst[0]);
	if (!ft_strncmp(inst, "rra", 3))
		rra(table);
	else if (!ft_strncmp(inst, "rrb", 3))
		rrb(table);
	else if (!ft_strncmp(inst, "rrr", 3))
		rrr(table);
	else if (!ft_strncmp(inst, "sa", 2))
		sa(table);
	else if (!ft_strncmp(inst, "sb", 2))
		sb(table);
	else if (!ft_strncmp(inst, "ss", 2))
		ss(table);
	else if (!ft_strncmp(inst, "pa", 2))
		pa(table);
	else if (!ft_strncmp(inst, "pb", 2))
		pb(table);
	else if (!ft_strncmp(inst, "ra", 2))
		ra(table);
	else if (!ft_strncmp(inst, "rb", 2))
		rb(table);
	else if (!ft_strncmp(inst, "rr", 2))
		rr(table);
	else
		return (false);
	return (true);
}
