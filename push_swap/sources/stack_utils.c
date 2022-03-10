/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:09:02 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/11 01:34:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
    	if (arr[j] <= pivot) 
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
    ft_swap(&arr[i + 1], &arr[high]);
	return(i + 1);
}

void	doQuickSort(int *arr, int low, int high)
{
	int	pivot;
	if (low < high)
	{
		pivot =  partition(arr, low, high);
		doQuickSort(arr, low, pivot - 1);
		doQuickSort(arr, pivot + 1, high);
	}
}

t_bool	CheckIfSorted(t_stack **stack)
{
	t_stack	*tmp;
	
	tmp = *stack;
	while(tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return(false);
		tmp = tmp->next;
	}
	return(true);
}

int	CountStackElems(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = *stack;
	while(tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
} 

t_stack	*StackInit(int argc, char **argv)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!argc)
		return (NULL);
	tmp->data = ft_atoi(*argv);
	tmp->next = StackInit(argc - 1, argv + 1);
	return(tmp);
}
