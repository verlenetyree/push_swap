/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:11:30 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/23 20:17:41 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//sa (swap a):
//swap the first 2 elements at the top of stack a.
//do nothing if there is only one or no elements.

void	do_sa(t_stack **a_stack, t_bool status)
{
	t_stack	*tmp;

	if (*a_stack && (*a_stack)->next)
	{
		tmp = (*a_stack)->next;
		(*a_stack)->next = tmp->next;
		tmp->next = *a_stack;
		*a_stack = tmp;
	}
	if (status == true)
		ft_putstr_fd("sa\n", 1);
}

//pa (push a):
//take the first element at the top of b and put it at the top of a.

void	do_pa(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	t_stack	*tmp;

	if (*b_stack)
	{
		tmp = *b_stack;
		*b_stack = (*b_stack)->next;
		tmp->next = *a_stack;
		*a_stack = tmp;
	}
	if (status == true)
		ft_putstr_fd("pa\n", 1);
}

//ra (rotate a):
//shift up all elements of stack a by 1.
//the first element becomes the last one.

void	do_ra(t_stack **a_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*a_stack && (*a_stack)->next)
	{
		last = (*a_stack)->next;
		tmp = (*a_stack);
		while (last->next)
			last = last->next;
		last->next = tmp;
		*a_stack = (*a_stack)->next;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("ra\n", 1);
}

//rra (reverse rotate a):
//shift down all elements of stack a by 1.
//the last element becomes the first one.

void	do_rra(t_stack **a_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = (*a_stack);
	last = NULL;
	if (*a_stack && (*a_stack)->next)
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
		last->next = (*a_stack);
		*a_stack = last;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("rra\n", 1);
}
