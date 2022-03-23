/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:50:35 by admin             #+#    #+#             */
/*   Updated: 2022/03/23 20:20:42 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	doParamsCalculation(t_stack **stack, t_params *params)
{
	int		i;
	int		size;
	int		*arr;

	i = 0;
	params->a_size = CountStackElems(stack);
	params->b_size = 0;
	size = params->a_size;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
		return (false);
	fill_array(arr, size, stack);
	doQuickSort(arr, 0, size - 1);
	params->min = arr[0];
	params->max = arr[size - 1];
	params->med = arr[size / 2];
	free(arr);
	return (true);
}

void	doFinalSort(t_stack **a_stack, t_params *params)
{
	int			i;
	int			size;
	t_stack		*tmp;

	size = params->a_size;
	tmp = *a_stack;
	i = 0;
	while (tmp->data != params->min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > size / 2)
		while ((*a_stack)->data != params->min)
			do_rra(a_stack, true);
	else
		while ((*a_stack)->data != params->min)
			do_ra(a_stack, true);
}

void	doSmallSort(t_stack **a_stack, t_params *params)
{
	t_stack	*b_stack;
	int		size;

	b_stack = NULL;
	size = params->a_size;
	if (size == 3)
		doThreeSort(a_stack);
	if (size > 3)
	{
		params->a_size = 3;
		params->b_size = size - 3;
		while (size > 3)
		{
			if ((*a_stack)->data == params->min || \
				(*a_stack)->data == params->max)
			{
				do_pb(a_stack, &b_stack, true);
				size--;
			}
			else
				do_ra(a_stack, true);
		}
		doCompleteSort(a_stack, &b_stack, params);
	}
}

void	doMainSort(t_stack **a, t_params *params)
{
	t_stack	*b;

	b = bStackInit(a, params);
	while (b)
	{
		doScoreCalculation(a, &b, params);
		doProcessing(a, &b, params);
	}
}

void	doSort(t_stack **a)
{
	t_params	params;

	if (!doParamsCalculation(a, &params))
		return ;
	if (!CheckIfSorted(a))
	{
		if (params.a_size <= 5)
			doSmallSort(a, &params);
		else
			doMainSort(a, &params);
		doFinalSort(a, &params);
	}
}
