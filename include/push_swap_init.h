/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:03:05 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 11:42:21 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTIL_H
# define PUSH_SWAP_UTIL_H
# include "deque.h"
# include "ab_table.h"

typedef struct s_compre
{
	int		origin;
	size_t	compre;
}	t_compre;

int			is_duplicate(size_t len, int *list);
t_deque		*convert_deque(size_t len, int	*array, t_deque *node, int *cp_array);
t_abtable	*push_swap_init(size_t len, int	*array);
#endif
