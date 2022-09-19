/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 15:01:19 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "push_swap_util.h"
#include "quick_sort.h"
#include "deque.h"
#include "deque_util.h"

int	push_swap(size_t len, int *array)
{
	size_t	i;
	t_deque	*deque_node;

	deque_node = convert_deque(len, array);
	if (!deque_node)
		return (false);
	if (is_duplicate(len, array))
		return (false);

	i = 0;
	printf("len=%zu\n", len);
	while (i < len)
	{
		//add_back(deque_node, &(array[i]));
		printf("array[%zu]=%d\n", i, array[i]);
		i++;
	}
	qsort_asce(array, array[len / 2], 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("array[%zu]=%d\n", i, array[i]);
		i++;
	}
	qsort_desc(array, array[len / 2], 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("array[%zu]=%d\n", i, array[i]);
		i++;
	}
	return (true);
}
