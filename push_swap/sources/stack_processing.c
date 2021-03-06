/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:30:54 by vtyree            #+#    #+#             */
/*   Updated: 2022/03/25 14:56:32 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	processBScore(t_stack **b, t_stack *elem)
{
	while (elem->b_score)
	{
		if (elem->b_score > 0)
		{
			do_rb(b, true);
			elem->b_score--;
		}
		if (elem->b_score < 0)
		{
			do_rrb(b, true);
			elem->b_score++;
		}
	}
}

static void	processAScore(t_stack **a, t_stack *elem)
{
	if (elem->a_score > 0)
	{
		do_ra(a, true);
		elem->a_score--;
	}
	if (elem->a_score < 0)
	{
		do_rra(a, true);
		elem->a_score++;
	}
}

static void	processNegative(t_stack **a, t_stack **b, t_stack *elem)
{
	while (elem->a_score < 0 && elem->b_score < 0)
	{
		do_rrr(a, b, true);
		elem->a_score++;
		elem->b_score++;
	}
	while (elem->a_score++ < 0)
		do_rra(a, true);
	while (elem->b_score++ < 0)
		do_rrb(b, true);
}

static void	processPositive(t_stack **a, t_stack **b, t_stack *elem)
{
	while (elem->a_score > 0 && elem->b_score > 0)
	{
		do_rr(a, b, true);
		elem->a_score--;
		elem->b_score--;
	}
	while (elem->a_score-- > 0)
		do_ra(a, true);
	while (elem->b_score-- > 0)
		do_rb(b, true);
}

void	doProcessing(t_stack **a, t_stack **b, t_params *params)
{
	t_stack	*tmp;
	t_stack	*min;

	min = *b;
	tmp = *b;
	while (tmp)
	{
		if (min->score > tmp->score)
			min = tmp;
		tmp = tmp->next;
	}
	if (min->a_score > 0 && min->b_score > 0)
		processPositive(a, b, min);
	else if (min->a_score < 0 && min->b_score < 0)
		processNegative(a, b, min);
	else
	{
		while (min->a_score)
			processAScore(a, min);
		while (min->b_score)
			processBScore(b, min);
	}
	do_pa(a, b, true);
	params->a_size++;
	params->b_size--;
}
