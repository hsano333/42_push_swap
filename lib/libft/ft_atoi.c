/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:42:24 by hsano             #+#    #+#             */
/*   Updated: 2022/09/19 01:55:06 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_digit_len(const char *str, size_t i, int *error)
{
	size_t	len;

	len = i;
	while (str[len])
	{
		if ('0' <= str[len] && str[len] <= '9')
			len++;
		else
		{
			*error = true;
			break ;
		}
	}
	return (len - i);
}

size_t	get_start_index(const char *str, int *minus)
{
	size_t	i;

	i = 0;
	*minus = 1;
	while (true)
	{
		if (str[i] == ' ' || (0x09 <= str[i] && str[i] <= 0x0D))
			i++;
		else
		{
			if (str[i] == '+')
				i++;
			else if (str[i] == '-')
			{
				i++;
				*minus = -1;
			}
			break ;
		}
	}
	return (i);
}

size_t	ft_iterative_power(long nb, long power, int *error)
{
	size_t	rval;
	size_t	old;

	rval = (long)nb;
	if (*error)
		return (0);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	*error = true;
	while (--power)
	{
		old = rval;
		rval = nb * rval;
		if (old > rval)
			return (LONG_MAX);
	}
	*error = false;
	return (rval);
}

size_t	remove_zero(const char *str, size_t i, int *error)
{
	if (i > 0)
	{
		if (str[i - 1] == '+' || str[i - 1] == '-')
		{
			if (!ft_isdigit(str[i]))
			{
				*error = true;
				return (0);
			}
		}
	}
	*error = false;
	while (str[i] == '0')
		(i)++;
	return (i);
}

int	ft_atoi(const char *str, int *error)
{
	int		minus;
	size_t	len;
	size_t	i;
	size_t	sum;
	size_t	a;

	i = remove_zero(str, get_start_index(str, &minus), error);
	sum = 0;
	len = get_digit_len(str, i, error);
	a = ft_iterative_power(10, len - 1, error);
	while (a > 0)
	{
		sum += (str[i++] - '0') * a;
		if ((sum > INT_MAX && minus == 1) || (sum > (INT_MAX) + 1UL))
			*error = true;
		if (sum > LONG_MAX)
		{
			if (minus == -1 || sum == (LONG_MAX))
				minus = 0;
			sum = -1;
			break ;
		}
		a /= 10;
	}
	return ((int)(sum * minus));
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	int len;
//	int	result;
//	int error;
//
//	result = 0;
//	printf("LONGMAX=%ld\n",LONG_MAX);
//	printf("INTMAX=%d\n",INT_MAX);
//	if (argc == 2)
//	{
//		s1 = argv[1];
//		//s1 = "\t\v\f\r\n \f-06050";
//		len = atoi(s1);
//		result = ft_atoi(s1, &error);
//		printf("input:%s\n",s1);
//		printf("my:%d, error=%d\n",result, error);
//		printf("test:%d\n",len);
//	}
//
//	return (0);
//}
