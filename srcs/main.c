/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:50:54 by hsano             #+#    #+#             */
/*   Updated: 2022/09/24 01:50:49 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libft_str.h"
#include "push_swap.h"
#include "ft_printf.h"

static int	list_atoi(size_t len, char **argv, int **list)
{
	size_t	i;
	int		error;

	*list = (int *)malloc(sizeof(int) * len);
	if (!*list)
		return (false);
	i = 0;
	while (i < len)
	{
		(*list)[i] = ft_atoi(argv[i], &error);
		if (error)
			return (false);
		i++;
	}
	return (true);
}

static size_t	split_argv(char *argv, int **list)
{
	char	**split;
	size_t	len;
	int		result;

	split = ft_split(argv, ' ');
	if (!split)
		return (false);
	len = 0;
	while (split[len])
		len++;
	result = list_atoi(len, split, list);
	ft_free_split(split);
	if (!result)
		len = 0;
	return (len);
}

static size_t	convert_argv_to_list(int argc, char **argv, int **list)
{
	size_t	len;

	if (argc == 2)
		len = split_argv(argv[1], list);
	else if (argc > 2)
	{
		if (list_atoi(argc - 1, &(argv[1]), list))
			len = argc - 1;
		else
			len = 0;
	}
	if (*list == NULL)
		len = 0;
	return (len);
}

int	main(int argc, char **argv)
{
	int		*list;
	int		rval;
	size_t	len;

	list = NULL;
	len = convert_argv_to_list(argc, argv, &list);
	if (len && list)
	{
		rval = push_swap(len, list);
		if (rval == false)
			ft_printf("ERROR\n");
	}
	else
		ft_printf("ERROR\n");
	free(list);
	return (true);
}
