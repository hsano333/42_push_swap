/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_command.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:27:51 by hsano             #+#    #+#             */
/*   Updated: 2022/09/23 01:57:47 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAN_COMMAND_H
# define CAN_COMMAND_H
#include "quick_sort.h"
#include "ab_table.h"
#include "deque.h"
#include "deque_util.h"

int		is_ss(t_abtable *table);
int		is_sa(t_abtable *table, char target, t_pivot pivot);
int		is_sb(t_abtable *table, char target, t_pivot pivot);
int		is_rrr(t_abtable *table);
int		is_rra(t_abtable *table);
int		is_rrb(t_abtable *table);
void	execute_shift(t_abtable *table, char target, t_pivot pivot);
void	execute_reverse(t_abtable *table);
void	execute_rotate(t_abtable *table, char target, int force);
#endif
