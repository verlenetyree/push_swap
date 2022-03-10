/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:50:35 by admin             #+#    #+#             */
/*   Updated: 2022/03/11 01:08:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_bool	doParamsCalculation(t_stack **stack, t_params *params, int size)
{
	int		i;
	int		*arr;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
		return(false);
	fill_array(arr, size, stack);
	doQuickSort(arr, 0, size - 1);
	params->min = arr[0];
	params->max = arr[size - 1];
	params->med = arr[size / 2];
	free(arr);
	return (true);
}

void	doFinalSort(t_stack **a_stack)
{
	int			i;
	int			size;
	t_params	a_params;
	t_stack		*tmp;
	
	size = CountStackElems(a_stack);
	if(!doParamsCalculation(a_stack, &a_params, size)) // попробовать посчитать ещё раньше
		return ;
	tmp = *a_stack;
	i = 0;
	while(tmp->data != a_params.min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > size / 2)
		while ((*a_stack)->data != a_params.min)
			do_rra(a_stack, true);
	else
		while ((*a_stack)->data != a_params.min)
			do_ra(a_stack, true);
}

void	doSmallSort(t_stack **a_stack)
{
	int	a;
	int	b;
	int	c;
	
	a = (*a_stack)->data;
	b = (*a_stack)->next->data;
	c = (*a_stack)->next->next->data;
	if (a > b && b > c) //643
		do_sa(a_stack, true);
	if (c > a && a > b) //436
		do_sa(a_stack, true);
	if (c > a && b > c) //364
		do_sa(a_stack, true);
}

void	doSort(t_stack **a)
{
	if (!CheckIfSorted(a))
	{
		if (CountStackElems(a) <= 3)
			doSmallSort(a);
		doFinalSort(a);
	}
}