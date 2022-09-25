/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:34 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 16:42:08 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ab_table.h"
#include "push_swap_init.h"
#include "deque.h"
#include "quick_sort.h"

int	*copy_array(size_t len, int *array)
{
	int		*cp_array;
	size_t	i;

	cp_array = (int *)malloc(sizeof(int) * len);
	if (!cp_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cp_array[i] = array[i];
		i++;
	}
	return (cp_array);
}

int	is_duplicate(size_t len, int *array)
{
	size_t	i;
	int		result;

	result = false;
	qsort_asce(array, array[len / 2], 0, len - 1);
	i = 0;
	while (i < len - 1)
	{
		if (array[i] == array[i + 1])
		{
			result = true;
			break ;
		}
		i++;
	}
	return (result);
}

t_compre	*create_t_compre(int origin, size_t compre)
{
	t_compre	*val;

	val = (t_compre *)malloc(sizeof(t_compre) * 1);
	if (!val)
		return (NULL);
	val->origin = origin;
	val->compre = compre;
	val->id = 0;
	return (val);
}

t_deque	*convert_deque(size_t len, int	*array, t_deque *node, int *cp_array)
{
	t_compre	*compre;
	size_t		i;
	size_t		j;

	qsort_asce(cp_array, cp_array[len / 2], 0, len - 1);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (array[j] != cp_array[i])
			i++;
		compre = create_t_compre(array[j], i);
		if (!push_back(node, (void *)compre))
		{
			clear_deque(node);
			return (NULL);
		}
		j++;
	}
	return (node);
}

t_abtable	*push_swap_init(size_t len, int	*array, int put_flag)
{
	t_deque		*table_a;
	t_deque		*table_b;
	int			*cp_array;

	if (!array || len == 0)
		return (NULL);
	table_a = init_deque();
	table_b = init_deque();
	cp_array = copy_array(len, array);
	if (!cp_array || !table_a || !table_b || is_duplicate(len, cp_array))
	{
		free(cp_array);
		clear_deque(table_a);
		clear_deque(table_b);
		return (NULL);
	}
	table_a = convert_deque(len, array, table_a, cp_array);
	free(cp_array);
	return (create_ab_table(table_a, table_b, put_flag));
}
