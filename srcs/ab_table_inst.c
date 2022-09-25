/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:43:15 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 20:41:28 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ab_table.h"
#include "libft_mem.h"

int	execute_str_instruction(t_abtable *table, char *inst)
{
	if (!ft_memcmp(inst, "rra", 4))
		rra(table);
	else if (!ft_memcmp(inst, "rrb", 4))
		rrb(table);
	else if (!ft_memcmp(inst, "rrr", 4))
		rrr(table);
	else if (!ft_memcmp(inst, "sa", 3))
		sa(table);
	else if (!ft_memcmp(inst, "sb", 3))
		sb(table);
	else if (!ft_memcmp(inst, "ss", 3))
		ss(table);
	else if (!ft_memcmp(inst, "pa", 3))
		pa(table);
	else if (!ft_memcmp(inst, "pb", 3))
		pb(table);
	else if (!ft_memcmp(inst, "ra", 3))
		ra(table);
	else if (!ft_memcmp(inst, "rb", 3))
		rb(table);
	else if (!ft_memcmp(inst, "rr", 3))
		rr(table);
	else
		return (false);
	return (true);
}
