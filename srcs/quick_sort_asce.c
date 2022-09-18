/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_asce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:08:35 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 02:42:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define LF "\n "

static int	left_loop(int *val, int pivot, int begin_ri, int li)
{
	while (li <= begin_ri)
	{
		if (val[li] >= pivot)
			break ;
		li++;
	}
	return (li);
}

static int	right_loop(int *val, int pivot, int begin_li, int ri)
{
	while (ri >= begin_li)
	{
		if (val[ri] <= pivot)
			break ;
		ri--;
	}
	return (ri);
}

void	qsort_asce(int *val, int pivot, int li, int ri)
{
	int	begin_li;
	int	begin_ri;
	int	tmp;

	begin_li = li;
	begin_ri = ri;
	while (1)
	{
		li = left_loop(val, pivot, begin_ri, li);
		ri = right_loop(val, pivot, begin_li, ri);
		if (li >= ri)
			break ;
		tmp = (val[li]);
		val[li] = val[ri];
		val[ri] = tmp;
		li++;
		ri--;
	}
	if (li - 1 > begin_li)
		qsort_asce(val, val[(li - 1 + begin_li) / 2], begin_li, li - 1);
	if (ri + 1 < begin_ri)
		qsort_asce(val, val[(ri + 1 + begin_ri) / 2], ri + 1, begin_ri);
}
//
//int	main(int argc, char *argv[])
//{
//	int		i;
//	int		j;
//	char	*str;
//
//	quick_sort(argv, &(argv[argc / 2][0]), 1, argc - 1);
//	if (argc > 1)
//	{
//		i = 1;
//		j = 0;
//		while (i < argc)
//		{
//			while (argv[i][j])
//			{
//				str = (argv[i]);
//				write(1, &(argv[i][j]), 1);
//				j++;
//			}
//			write(1, &(LF[0]), 1);
//			j = 0;
//			i++;
//		}
//	}
//}
