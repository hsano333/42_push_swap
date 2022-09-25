/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:03:05 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 16:41:52 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INIT_H
# define PUSH_SWAP_INIT_H
# include "deque.h"
# include "ab_table.h"

int			is_duplicate(size_t len, int *list);
void		reverse_a(t_abtable *table);
t_deque		*convert_deque(size_t len, int	*array, t_deque *node, \
														int *cp_array);
t_abtable	*push_swap_init(size_t len, int	*array, int put_flag);
#endif
