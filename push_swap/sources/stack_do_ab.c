/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_do_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:36:08 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/10 17:19:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//ss : sa and sb at the same time.

void	do_ss(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_sa(a_stack, false);
	do_sb(b_stack, false);
	if (status == true)
		ft_putstr_fd("ss\n", 1);
}

//rr : ra and rb at the same time.

void	do_rr(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_ra(a_stack, false);
	do_rb(b_stack, false);
	if (status == true)
		ft_putstr_fd("rr\n", 1);
}

//rrr : rra and rrb at the same time.

void	do_rrr(t_stack **a_stack, t_stack **b_stack, t_bool status)
{
	do_rra(a_stack, false);
	do_rrb(b_stack, false);
	if (status == true)
		ft_putstr_fd("rrr\n", 1);
}
