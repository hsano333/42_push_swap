/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:58:36 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 10:17:41 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "push_swap_util.h"
#include "quick_sort.h"

int	push_swap(size_t len, int *list_i)
{
	size_t	i;

	if (is_duplicate(len, list_i))
		return (false);

	i = 0;
	printf("len=%zu\n", len);
	while (i < len)
	{
		printf("list[%zu]=%d\n", i, list_i[i]);
		i++;
	}
	qsort_asce(list_i, list_i[len / 2], 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("list[%zu]=%d\n", i, list_i[i]);
		i++;
	}
	qsort_desc(list_i, list_i[len / 2], 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("list[%zu]=%d\n", i, list_i[i]);
		i++;
	}
	return (true);
}
