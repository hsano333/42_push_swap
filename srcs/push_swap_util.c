/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:54:34 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 10:17:56 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "quick_sort.h"

int	is_duplicate(size_t len, int *list)
{
	int		*cp_list;
	size_t	i;
	int		result;

	result = false;
	cp_list = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		cp_list[i] = list[i];
		i++;
	}
	qsort_asce(cp_list, cp_list[len / 2], 0, len - 1);
	i = 0;
	while (i < len - 1)
	{
		if (cp_list[i] == cp_list[i + 1])
		{
			result = true;
			break;
		}
		i++;
	}
	free(cp_list);
	return (result);
}
