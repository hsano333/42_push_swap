/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:34 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 15:32:55 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "push_swap_util.h"
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
	printf("No.1 val=%p\n", val);
	if (!val)
		return (NULL);
	printf("No.2 val=%p\n", val);
	val->origin = origin;
	val->compre = compre;
	printf("No.3 val=%p\n", val);
	return (val);
}


t_deque	*convert_deque(size_t len, int	*array)
{
	int			*cp_array;
	t_deque		*node;
	t_compre	*compre;
	int			error;

	error = false;
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
	qsort_asce(cp_array, cp_array[len / 2], 0, len - 1);
	while (len--)
	{
		printf("No.1 cp_array[%zu]=%d\n", len, cp_array[len]);
		compre = create_t_compre(cp_array[len], len);
		printf("No.2 cp_array[%zu]=%d, compre=%p\n", len, cp_array[len], compre);
		if (!compre)
			error = true;
		printf("No.3 cp_array[%zu]=%d, error=%d\n", len, cp_array[len], error);
		add_back(node, (void *)compre);
		printf("No.4 cp_array[%zu]=%d\n", len, cp_array[len]);
	}
	put_all(node);
	//free(cp_array);
	return (node);
}
