/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:02 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 18:49:29 by hsano            ###   ########.fr       */
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
#include "libft_str.h"

int	push_swap_checker(size_t len, int *array)
{
	int			result;
	char		*line;
	t_abtable	*ab_table;
	int			ng_flag;

	ab_table = push_swap_init(len, array, false);
	if (!ab_table)
		return (false);
	ng_flag = false;
	while (1)
	{
		line = get_next_line(0);
		if (line)
			result = execute_str_instruction(ab_table, line);
		else
		//{
			//ng_flag = true;
			//ft_printf("KO\n");
			break ;
		//}
		free(line);
		if (result == false)
		{
			ng_flag = true;
			//ft_printf("Error\n");
			break ;
		}
	}
	if (ng_flag)
		ft_printf("Error\n");
	else if (can_sort(ab_table, BOTH_TABLE))
		ft_printf("KO\n");
	else 
		ft_printf("OK\n");
	clear_ab_table(ab_table);
	return (true);
}
