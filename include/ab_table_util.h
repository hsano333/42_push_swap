/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:09 by hsano             #+#    #+#             */
/*   Updated: 2022/09/23 22:48:48 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AB_TABLE_UTIL_H
# define AB_TABLE_UTIL_H
# include "ab_table.h"
# include "deque.h"
int		get_node_id(t_deque *node);
int		is_less_than_four_table_a(t_abtable *table);
void	rotation_for_reverse(t_abtable *table);
void	init_flag(t_abtable *table, char target);
t_deque	*countup_table_id(t_abtable *table, char target);
#endif
