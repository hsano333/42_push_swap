/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:02 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 15:48:57 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
# include <stdlib.h>
# include <stdbool.h>
# include "push_swap_init.h"
# include "ab_table.h"
# include "push_swap_util.h"
#include "get_next_line.h"
#include "ft_printf.h"

int	push_swap_checker(size_t len, int *array)
{
	int			result;
	char		*line;
	t_abtable	*ab_table;

	ab_table = push_swap_init(len, array);
	if (!ab_table)
		return (false);
	while (can_sort(ab_table, BOTH_TABLE))
	{
		line = get_next_line(0);
		result = execute_str_instruction(ab_table, line);
		free(line);
		if (result == false)
		{
			ft_printf("Error\n");
			break;
		}
	}
	clear_ab_table(ab_table);
	return (true);
}
