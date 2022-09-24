/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:59 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 16:48:15 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AB_TABLE_H
# define AB_TABLE_H
# include "deque.h"
# include "ft_printf.h"
# define A_TABLE 'A'
# define B_TABLE 'B'
# define BOTH_TABLE 'C'
# define FINAL 'F'

typedef struct s_abtable
{
	t_deque	*a;
	t_deque	*b;
	size_t	no;
	int		reverse_count_a;
	int		reverse_count_b;
	int		put_flag;
	int		ra_flag;
	int		rb_flag;
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
void		divide_ab_table(t_abtable *table, char target);
void		clear_ab_table(t_abtable *table);
int			get_id(t_deque node);
void		execute_str_instruction(t_abtable *table, char *inst);
t_abtable	*create_ab_table(t_deque *a, t_deque *b);
#endif
