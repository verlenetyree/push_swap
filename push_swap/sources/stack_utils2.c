/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:55:23 by admin             #+#    #+#             */
/*   Updated: 2022/03/23 20:20:50 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*bStackInit(t_stack **a, t_params *params)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = params->a_size;
	params->b_size = size - 3;
	while (size > 3)
	{
		if ((*a)->data == params->min || (*a)->data == params->max || \
			(*a)->data == params->med)
			do_ra(a, true);
		else
		{
			do_pb(a, &b, true);
			if (b->data > params->med)
				do_rb(&b, true);
			size--;
		}
	}
	params->a_size = 3;
	doThreeSort(a);
	doFinalSort(a, params);
	return (b);
}

t_stack	*GetStackLastElement(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	doThreeSort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b > c)
		do_sa(stack, true);
	if (c > a && a > b)
		do_sa(stack, true);
	if (c > a && b > c)
		do_sa(stack, true);
}

void	doCompleteSort(t_stack **a_stack, t_stack **b_stack, t_params *params)
{
	t_params	fake_param;

	doThreeSort(a_stack);
	if (!CheckIfSorted(a_stack))
	{
		doParamsCalculation(a_stack, &fake_param);
		doFinalSort(a_stack, &fake_param);
	}
	while (params->b_size)
	{
		if ((*b_stack)->data == params->max)
		{
			do_pa(a_stack, b_stack, true);
			do_ra(a_stack, true);
		}
		else
			do_pa(a_stack, b_stack, true);
		params->b_size--;
	}
}
