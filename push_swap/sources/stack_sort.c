/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:50:35 by admin             #+#    #+#             */
/*   Updated: 2022/03/11 16:50:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_bool	doParamsCalculation(t_stack **stack, t_params *params)
{
	int		i;
	int		size;
	int		*arr;
	
	i = 0;
	params->size = CountStackElems(stack);
	size = params->size;
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

void	doFinalSort(t_stack **a_stack, t_params *a_params)
{
	int			i;
	int			size;
	t_stack		*tmp;

	size = a_params->size;
	// if(!doParamsCalculation(a_stack, a_params)) // попробовать посчитать ещё раньше
	// 	return ;
	tmp = *a_stack;
	i = 0;
	while(tmp->data != a_params->min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > size / 2)
		while ((*a_stack)->data != a_params->min)
			do_rra(a_stack, true);
	else
		while ((*a_stack)->data != a_params->min)
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

void	doScoreCalculation_b(t_stack **b)
{
	//исходя из положения элемента в стеке б можно подсчитать требуемое кол-во операций
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	size = CountStackElems(b);
	while (i++ < size / 2) //rb
	{
		tmp->score = i;
		tmp = tmp->next; //rrb
	}
	while (i-- < size)
	{
		tmp->score = i;
		tmp = tmp->next;
	}
}

void	doMainSort(t_stack *a, t_params *a_params)
{
	// int		size_a;
	// int		size_b;
	t_stack	*b;
	t_stack	tmp;
	
	b = bStackInit(a, a_params);
	doScoreCalculation_b(&b);
	
}

void	doSort(t_stack **a)
{
	t_params	a_params;
	
	if(!doParamsCalculation(a, &a_params)) // попробовать посчитать ещё раньше
		return ;
	printf("min: %d, max: %d, med: %d\n\n", a_params.min, a_params.max, a_params.med);
	if (!CheckIfSorted(a))
	{
		if (a_params.size == 3)
			doSmallSort(a);
		else // cделать проверку на предварительную сортировку
			doMainSort(*a, &a_params);
		doFinalSort(a, &a_params);
	}
}