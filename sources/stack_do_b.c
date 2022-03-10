/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:11:30 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 05:32:21 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_sb(t_stack **b_stack, t_bool status)
{
	t_stack	*tmp;

	if (*b_stack && (*b_stack)->next)
	{
		tmp = (*b_stack)->next;
		(*b_stack)->next = tmp->next;
		tmp->next = *b_stack;
		*b_stack = tmp;
	}
	if (status == true)
		ft_putstr_fd("sb\n", 1);
}

void	do_pb(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	t_stack	*tmp;

	if (*a_stack)
	{
		tmp = *a_stack;
		*a_stack = (*a_stack)->next;
		tmp->next = *b_stack;
		*b_stack = tmp;
	}
	if (status == true)
		ft_putstr_fd("pb\n", 1);
}

void	do_rb(t_stack **b_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*b_stack && (*b_stack)->next)
	{
		last = (*b_stack)->next;
		tmp = (*b_stack);
		while (last->next)
			last = last->next;
		last->next = tmp;
		*b_stack = (*b_stack)->next;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("rb\n", 1);
}


void	do_rrb(t_stack **b_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*b_stack && (*b_stack)->next)
	{
		tmp = (*b_stack)->next;
		last = (*b_stack);
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->next->next)
			{
				last = tmp->next;
				break ;
			}
		}
		last->next = (*b_stack);
		*b_stack = last;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("rrb\n", 1);
}
