/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_three_node.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 02:58:53 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 15:45:16 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_OR_THREE_NODE_H
# define TWO_OR_THREE_NODE_H
# define INSTRUCTIONS_A   "s"
# define INSTRUCTIONS_B   "r s re"
# define INSTRUCTIONS_BA  "r s re s"
# define INSTRUCTIONS_AB  "s r s re "
# define INSTRUCTIONS_ABA "s r s re s"
# define INSTRUCTIONS_C   "r"
# define INSTRUCTIONS_D   "re"
# define INSTRUCTIONS_AD   "s re"
# define INSTRUCTIONS_CAD   "r s re"

# include "ab_table.h"
# include "deque.h"
# include "limits.h"

int		is_two_or_three_node(t_abtable *table);
void	two_or_three_node(t_abtable *table);
char	*two_or_three_node_a(t_abtable *table);
char	*two_or_three_node_b(t_abtable *table);
char	*get_common_instruction(char *inst_a, char *inst_b, \
											int len_a, int len_b);
void	execute_str_inst_wrapper(t_abtable *table, char *inst, char target);
void	execute_str_both_inst_wrapper(t_abtable *table, char *inst);
int		is_only_two_or_three_node_in_table(t_deque *node);
char	*only_two_or_three_node_inst(char target, char *numbers);
#endif
