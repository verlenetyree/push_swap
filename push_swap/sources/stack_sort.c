/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:50:35 by admin             #+#    #+#             */
/*   Updated: 2022/03/18 20:20:25 by vtyree           ###   ########.fr       */
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

void	doThreeSort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b > c) //643
		do_sa(stack, true);
	if (c > a && a > b) //436
		do_sa(stack, true);
	if (c > a && b > c) //364
		do_sa(stack, true);
}

void	doSmallSort(t_stack **a_stack, t_params *params)
{
	t_stack	*b_stack;
	int 	size;

	b_stack = NULL;
	size = params->a_size;
	if (size == 3)
		doThreeSort(a_stack);
	// if (size > 3)
	// {
	// 	params->a_size = 2;
	// 	params->b_size = size - 2;
	// 	while (size > 2)
	// 	{
	// 		if ((*a_stack)->data == params->min || (*a_stack)->data == params->max)
	// 			do_ra(a_stack, true);
	// 		else
	// 		{
	// 			do_pb(a_stack, &b_stack, true);
	// 			size--;
	// 		}
	// 	}
	// 	if (CheckIfSorted(a_stack))
	// 		do_ra(a_stack, true);
	// 	//doFinalSort(a_stack, params);
	// 	print_stack2(*a_stack);
	// 	print_stack2(b_stack);
	// 	// printf("size = %d\n", params->b_size);
	// 	if (params->b_size == 3 && !CheckIfSorted(&b_stack))
	// 		doThreeSort(&b_stack, false);
	// 	else if (!CheckIfSorted(&b_stack))
	// 		do_sb(&b_stack, true);
	// 	while (params->b_size--)
	// 		do_pa(a_stack, &b_stack, true);
	// 	print_stack2(*a_stack);
	// 	free(b_stack);
	// }
}


void	print_score(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->score);
		tmp = tmp->next;
	}
		printf("\n");
}

void	doMainSort(t_stack **a, t_params *params)
{
	t_stack	*b;

	b = bStackInit(a, params);
	// printf("\na: ");
	// print_stack2(*a);
	// printf("\nb: ");
	// print_stack2(b);
	// printf("\n---------\n");
	while (b)
	{
		doScoreCalculation(a, &b, params);

		// printf("\ns: ");
		// print_score(b);

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
		if (params.a_size <= 3)
			doSmallSort(a, &params);
		else /*if (!CheckIfPresorted(a,&params))*/ // if CheckIfPresorted() cделать проверку на предварительную сортировку
			doMainSort(a, &params);
		doFinalSort(a, &params);
	}
}
