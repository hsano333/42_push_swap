/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:59 by hsano             #+#    #+#             */
/*   Updated: 2022/09/20 17:04:56 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AB_TABLE_H
# define AB_TABLE_H
# include "deque.h"

typedef struct s_abtable
{
	t_deque	*a;
	t_deque	*b;
}	t_abtable;

void		sa(t_abtable *table);
void		sb(t_abtable *table);
void		ss(t_abtable *table);
void		pa(t_abtable *table);
void		pb(t_abtable *table);
void		ra(t_abtable *table);
void		rb(t_abtable *table);
void		rr(t_abtable *table);
void		rra(t_abtable *table);
void		rrb(t_abtable *table);
void		rrr(t_abtable *table);
void		put_table(t_abtable *table);
t_abtable	*create_ab_table(t_deque *a, t_deque *b);
#endif
