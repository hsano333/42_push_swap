/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_common.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:13:52 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 14:16:49 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_COMMON_H
# define MAIN_COMMON_H

#include <stdbool.h>
#include <stdlib.h>
#include "libft_str.h"
#include "push_swap.h"
#include "ft_printf.h"

size_t	convert_argv_to_list(int argc, char **argv, int **list);
#endif
