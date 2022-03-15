/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:55:23 by admin             #+#    #+#             */
/*   Updated: 2022/03/13 17:18:56 by vtyree           ###   ########.fr       */
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
	doSmallSort(a);
	doFinalSort(a, params);
	return (b);
}

t_stack	*GetStackLastElement(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_bool	CheckIfPresorted(t_stack **a, t_params *params)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = *a;
	tmp_next = tmp->next;
	while(tmp->next)
	{
		if (tmp->data < tmp_next->data)
		{
			tmp = tmp->next;
			tmp_next = tmp->next;
		}
		else if (tmp_next->data == params->min)
		{
			tmp_next = tmp_next->next;
			if (tmp_next->data > tmp->data)
				return (false);
			tmp = tmp->next;
		}
		else
			return (false);
	}
	return (true);
}
