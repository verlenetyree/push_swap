/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:55:23 by admin             #+#    #+#             */
/*   Updated: 2022/03/11 15:55:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*bStackInit(t_stack *a, t_params *a_params)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = a_params->size;
	while (size > 3)
	{
		if (a->data == a_params->min || a->data == a_params->max || \
			a->data == a_params->med)
			do_ra(&a, true);
		else
		{
			do_pb(&a, &b, true);
				if (b->data > a_params->med)
					do_rb(&b, true);
			size--;
		}
	}
	a_params->size = 3;
	doSmallSort(&a);
	doFinalSort(&a, a_params);

	printf("\na: ");
	print_stack2(a);
	printf("\nb: ");
	print_stack2(b);
	
	return (b);
}