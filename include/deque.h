/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:04:58 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 14:36:32 by hsano            ###   ########.fr       */
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
int		add_back(t_deque *src_node, void *content);
int		add_front(t_deque *src_node, void *content);
#endif
