/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:09:02 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 02:44:28 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*StackInit(int argc, char **argv)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!argc)
		return (NULL);
	tmp->data = ft_atoi(*argv);
	tmp->next = StackInit(argc - 1, argv + 1);
	return (tmp);
}
