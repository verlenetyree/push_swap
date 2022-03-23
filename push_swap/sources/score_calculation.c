/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:45:43 by vtyree            #+#    #+#             */
/*   Updated: 2022/03/18 16:31:17 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_a_score(int i, int size)
{
	int a_score;

	if (i < size - i)
		a_score = i;
	else
		a_score = (size - i) * -1;
	return (a_score);
}

void	doScoreCalculation_a(t_stack **a, t_stack **b, t_params *params)
{
	int		i;
	int		size;
	int		last_a;
	t_stack	*head_a;
	t_stack	*tmp_b;

	size = params->a_size;
	tmp_b = *b;
	while (tmp_b)
	{
		i = 0;
		head_a = *a;
		last_a = GetStackLastElement(a)->data;
		while (head_a)
		{
			if(tmp_b->data < head_a->data && tmp_b->data > last_a) //ra
				tmp_b->a_score = get_a_score(i, size);
			i++;
			last_a = head_a->data;
			head_a = head_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	doScoreCalculation_b(t_stack **b, t_params *params)
{
	int		i;
	int		j;
	int		size;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	size = params->b_size;
	while (i < size / 2) //rb
	{
		tmp->b_score = i++;
		tmp = tmp->next;
	}
	j = i;
	if (size % 2 != 0)
		i++;
	while (j++ < size) //rrb
	{
		tmp->b_score = i-- * -1;
		tmp = tmp->next;
	}
}

void	doScoreCalculation(t_stack **a, t_stack **b, t_params *params)
{
	t_stack	*tmp;

	doScoreCalculation_b(b, params);
	doScoreCalculation_a(a, b, params);
	tmp = *b;
	while (tmp)
	{
		tmp->score = ft_abs(tmp->a_score) + ft_abs(tmp->b_score);
		tmp = tmp->next;
	}
}
