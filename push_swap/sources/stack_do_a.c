/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:11:30 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 05:29:56 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	do_rra(t_stack **a_stack, t_bool status)
{
	t_stack	*last;
	t_stack	*tmp;

	if (*a_stack && (*a_stack)->next)
	{
		tmp = (*a_stack)->next;
		last = (*a_stack);
		while (tmp->next)
		{
			tmp = tmp->next;
			if (!tmp->next->next)
			{
				last = tmp->next;
				break ;
			}
		}
		last->next = (*a_stack);
		*a_stack = last;
		tmp->next = NULL;
	}
	if (status == true)
		ft_putstr_fd("rra\n", 1);
}

