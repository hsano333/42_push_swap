/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:02 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 20:43:04 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap_init.h"
#include "ab_table.h"
#include "push_swap_util.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft_str.h"

static void	put_output(int result, t_abtable *table)
{
	if (result == false)
		ft_printf("Error\n");
	else if (can_sort(table, BOTH_TABLE))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

static void	free_all(char *line, char *inst, t_abtable *table)
{
	free(line);
	free(inst);
	clear_ab_table(table);
}

int	push_swap_checker(size_t len, int *array)
{
	int			result;
	char		*inst;
	char		*line;
	t_abtable	*ab_table;

	ab_table = push_swap_init(len, array, false);
	if (!ab_table)
		return (false);
	while (1)
	{
		line = get_next_line(0);
		inst = ft_strtrim(line, "\n");
		result = true;
		if (line && inst)
			result = execute_str_instruction(ab_table, inst);
		else
			break ;
		if (!line || !inst || !result)
			break ;
		free(line);
		free(inst);
	}
	put_output(result, ab_table);
	free_all(line, inst, ab_table);
	return (true);
}
