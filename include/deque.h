/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:04:58 by hsano             #+#    #+#             */
/*   Updated: 2022/09/22 22:55:43 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include <stdbool.h>
//# include "deque_util.h"

typedef struct s_compre
{
	int		origin;
	size_t	compre;
	int		id;
}	t_compre;


typedef struct s_deque
{
	void			*prev;
	void			*next;
	t_compre		*content;
}	t_deque;
t_deque		*init_deque(void);
t_deque		*search_nil(t_deque *node);
int			is_empty(t_deque *node);
int			push_back(t_deque *src_node, t_compre *content);
int			push_front(t_deque *src_node, t_compre *content);
void		clear_deque(t_deque *node);
void		shift_up(t_deque *src_node);
void		shift_down(t_deque *src_node);
void		swap(t_deque *src_node);
t_compre	*pop_front(t_deque *src_node);
t_compre	*pop_back(t_deque *src_node);
int			equal_id(t_deque *a_node, t_deque *b_node);
void		update_id(t_deque *node, int id);
void		put_all(t_deque *node);
size_t		count_node(t_deque *node, int id);
#endif
