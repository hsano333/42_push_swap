/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:27:03 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 03:28:17 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H
# include <stdio.h>

typedef struct s_pivot
{
	size_t	small;
	size_t	middle;
	size_t	large;

}	t_pivot;

void	qsort_asce(int *val, int pivot, int li, int ri);
void	qsort_desc(int *val, int pivot, int li, int ri);
#endif
