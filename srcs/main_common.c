/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:13:16 by hsano             #+#    #+#             */
/*   Updated: 2022/09/25 14:16:41 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_common.h"

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

size_t	convert_argv_to_list(int argc, char **argv, int **list)
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
