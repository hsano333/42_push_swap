/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 19:03:09 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "push_swap_init.h"
#include "quick_sort.h"
#include "ab_table.h"
#include "deque.h"
#include "deque_util.h"

int	push_swap(size_t len, int *array)
{
	//size_t	i;
	t_abtable *ab_table;

	ab_table = push_swap_init(len, array);
	if (!ab_table)
		return (false);
	put_table(ab_table);
	pb(ab_table);
	put_table(ab_table);
	pb(ab_table);
	put_table(ab_table);
	pb(ab_table);

	printf("\ntest ra \n");
	rrr(ab_table);
	put_table(ab_table);
	rrr(ab_table);
	put_table(ab_table);
	rrr(ab_table);
	put_table(ab_table);
	rrr(ab_table);
	put_table(ab_table);
	/*
	printf("test No.1\n");
	printf("deque count:%zu\n", count_node(deque_node));
	put_all(deque_node);
	printf("test No.1 end\n\n");

	printf("test No.2, deque_node=%p\n",deque_node);
	t_compre	*test;
	test = NULL;
	swap(deque_node);
	put_all(deque_node);

	printf("test2-1 hang?, deque_node=%p\n",deque_node);
	t_compre	*val;
	val = (t_compre *)deque_node->content;
	if (val == NULL)
		printf("test2-2 hang?, val==NULL\n");
	printf("test2-3 hang?, val== notNULL, p=%p\n", deque_node);
	//.printf("contents: origin=%d, compre=%zu\n", val->origin, val->compre);
	shift_down(deque_node);
	if (test)
		printf("test No.3 pop front :origin=%d, compre=%zu\n", test->origin, test->compre);
	put_all(deque_node);
	printf("test3-3 hang?, val== notNULL, p=%p\n", deque_node);
	swap(deque_node);
	if (test)
		printf("test No.4 pop front :origin=%d, compre=%zu\n", test->origin, test->compre);
	put_all(deque_node);
	printf("test No.5 end\n\n");
	*/
	

	/*
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
	*/
	return (true);
}
