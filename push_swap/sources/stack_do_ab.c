/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:36:08 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 05:33:56 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ss(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_sa(a_stack, false);
	do_sb(b_stack, false);
	if (status == true)
		ft_putstr_fd("ss\n", 1);
}

void	do_rr(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_ra(a_stack, false);
	do_rb(b_stack, false);
	if (status == true)
		ft_putstr_fd("rr\n", 1);
}

void	do_rrr(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_rra(a_stack, false);
	do_rrb(b_stack, false);
	if (status == true)
		ft_putstr_fd("rrr\n", 1);
}
