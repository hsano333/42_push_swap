/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:04:58 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 01:22:03 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_deque
{
	void		*prev;
	void		*next;
	void		*content;
}	t_deque;
t_deque	*init_deque(void);
t_deque	*search_nil(t_deque *node);
int		is_empty(t_deque *node);
int		push_back(t_deque *src_node, void *content);
int		push_front(t_deque *src_node, void *content);
void	clear_deque(t_deque *node);
void*	pop_front(t_deque *src_node);
void*	pop_back(t_deque *src_node);
void	shift_up(t_deque *src_node);
void	shift_down(t_deque *src_node);
void	swap(t_deque *src_node);
size_t	count_node(t_deque *node);
#endif
