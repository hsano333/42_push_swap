/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:50:31 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 03:58:50 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_UTIL_H
# define DEQUE_UTIL_H
int		equal_id(t_deque *a_node, t_deque *b_node);
void	update_id(t_deque *node, int id);
void	put_all(t_deque *node);
#endif
