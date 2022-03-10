/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:49:35 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 02:46:14 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool CheckIfUnique(int argc, char **argv)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr == NULL)
		return (false);
	i = -1;
	while (++i < argc - 1)
		arr[i] = ft_atoi(argv[i + 1]);
	i = -1;
	j = 0;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 1)
		{
			if (arr[i] == arr[j])
			{
				free (arr);
				return(false);
			}
		}
	}
	free (arr);
	return (true);
}

static t_bool CheckIfInteger(char *elem)
{
	int64_t n;

	n = ft_atoi(elem);
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	return (true);
}


static t_bool CheckIfDigit(char *elem)
{
	while(*elem)
	{
		if (*elem == '+' || *elem == '-')
			elem++;
		while(*elem)
		{
			if (!ft_isdigit(*elem))
				return(false);
			elem++;
		}
	}
	return (true);
}

t_bool CheckIfValid(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (CheckIfDigit(argv[i]) == false)
			return(false);
		if (CheckIfInteger(argv[i]) == false)
			return(false);
		i++;
	}
	return (CheckIfUnique(argc, argv));
}
