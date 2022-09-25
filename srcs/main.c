/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:50:54 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 17:48:44 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_common.h"

int	main(int argc, char **argv)
{
	int		*list;
	int		rval;
	size_t	len;

	if (argc == 1)
		return (true);
	list = NULL;
	len = convert_argv_to_list(argc, argv, &list);
	if (len && list)
	{
		rval = push_swap(len, list);
		if (rval == false)
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	free(list);
	return (true);
}
