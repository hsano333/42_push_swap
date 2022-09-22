/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:50:46 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 14:23:37 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTIL_H
# define PUSH_SWAP_UTIL_H
# include "ab_table.h"
# include "limits.h"

int		can_sort(t_abtable *table, char target);
void	reverse_a(t_abtable *table);
#endif
