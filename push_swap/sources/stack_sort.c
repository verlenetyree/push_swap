/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:50:35 by admin             #+#    #+#             */
/*   Updated: 2022/03/13 18:27:36 by vtyree           ###   ########.fr       */
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
		return(false);
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
	//size = CountStackElems(a_stack);
	// if(!doParamsCalculation(a_stack, a_params)) // попробовать посчитать ещё раньше
	// 	return ;
	tmp = *a_stack;
	i = 0;
	while(tmp->data != params->min)
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

//можно сделать сортировку по шести элементам с разбивкой на два стека по три элемента

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

void	doMainSort(t_stack **a, t_params *params)
{
	t_stack	*b;

	b = bStackInit(a, params);
	while (b)
	{
		doScoreCalculation(a, &b, params);
		doProcessing(a, &b, params);
		// printf("\na: ");
		// print_stack2(*a);
		// printf("\nb: ");
		// print_stack2(b);
		// printf("\n---------\n");
	}
}

void	doSort(t_stack **a)
{
	t_params	params;

	if(!doParamsCalculation(a, &params)) // попробовать посчитать ещё раньше
		return ;
	//printf("min: %d, max: %d, med: %d\n\n", params.min, params.max, params.med);

	if (!CheckIfSorted(a))
	{
		if (params.a_size == 3)
			doSmallSort(a);
		else /*if (!CheckIfPresorted(a,&params))*/ // if CheckIfPresorted() cделать проверку на предварительную сортировку
			doMainSort(a, &params);
		doFinalSort(a, &params);
	}
}
