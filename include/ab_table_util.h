/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:09 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 03:27:36 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AB_TABLE_UTIL_H
# define AB_TABLE_UTIL_H
# include "ab_table.h"
# include "deque.h"

int		get_node_id(t_deque *node);
void	rotation_for_reverse(t_abtable *table);
void	init_flag(t_abtable *table, char target);
#endif
