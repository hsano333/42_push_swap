/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:34 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 16:24:55 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "push_swap_init.h"
#include "deque_util.h"
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
			break;
		}
		i++;
	}
	return (result);
}

t_compre	*create_t_compre(int origin, size_t compre)
{
	t_compre *val;

	val = (t_compre *)malloc(sizeof(t_compre *) * 1);
	if (!val)
		return (NULL);
	val->origin = origin;
	val->compre = compre;
	return (val);
}


t_deque	*convert_deque(size_t len, int	*array, t_deque *node, int *cp_array)
{
	t_compre	*compre;
	int			error;
	size_t		i;

	error = false;
	qsort_asce(cp_array, cp_array[len / 2], 0, len - 1);
	while (len--)
	{

		i = 0;
		while (array[len] != cp_array[i])
			i++;
		compre = create_t_compre(array[len], i);
		if (!compre)
			error = true;
		add_back(node, (void *)compre);
	}
	if (error)
	{
		clear_deque(node);
		return (false);
	}
	put_all(node);
	return (node);
}

t_deque	*push_swap_init(size_t len, int	*array)
{
	t_deque		*node;
	int			*cp_array;

	if (!array || len == 0)
		return (NULL);
	node = init_deque();
	cp_array = copy_array(len, array);
	if (!cp_array || !node)
	{
		free(cp_array);
		free(node);
		return (NULL);
	}
	node = convert_deque(len, array, node, cp_array);
	return (node);
}
