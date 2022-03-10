/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:00:54 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/11 01:31:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_array(int *arr, int size, t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	arr[size] = '\0';
	while (i < size)
	{
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	split_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}
