/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:03:05 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 14:33:32 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTIL_H
# define PUSH_SWAP_UTIL_H
# include "deque.h"

typedef struct s_compre
{
	int		origin;
	size_t	compre;
}	t_compre;

int		is_duplicate(size_t len, int *list);
t_deque	*convert_deque(size_t len, int	*array);
#endif
