/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:11:30 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/10 18:00:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//sb (swap b):
//swap the first 2 elements at the top of stack b.
//do nothing if there is only one or no elements.

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

//pb (push b): 
//take the first element at the top of a and put it at the top of b.
//do nothing if a is empty.

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

//rb (rotate b): 
//shift up all elements of stack b by 1. 
//the first element becomes the last one.

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

//rrb (reverse rotate b): 
//shift down all elements of stack b by 1. T
//the last element becomes the first one.

void	do_rrb(t_stack **b_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = (*b_stack);
	last = NULL;
	if (*b_stack && (*b_stack)->next)
	{
		while (tmp->next)
		{
			if (!tmp->next->next)
			{
				last = tmp->next;
				break ;
			}
			tmp = tmp->next;
		}
		last->next = (*b_stack);
		*b_stack = last;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("rrb\n", 1);
}
