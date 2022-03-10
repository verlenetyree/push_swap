/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:34:08 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/11 01:26:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // DELETE LATER

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648


typedef enum bool
{
	false,
	true
}	t_bool;

typedef enum ids
{
	none,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_ids;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_params
{
	int		min;
	int		max;
	int		med;
}			t_params;

// utils
int		split_count(char **arr);
void	free_array(char **arr);
void	fill_array(int *arr, int size, t_stack **stack);
void	free_stack(t_stack **stack);

//stack utils 
t_bool 	CheckIfValid(int argc, char **argv);
t_stack	*StackInit(int argc,char **argv);
int		CountStackElems(t_stack **stack);
t_bool	CheckIfSorted(t_stack **stack);

//operations
void	do_sa(t_stack **stack, t_bool status);
void	do_pa(t_stack **a_stack, t_stack **b_stack, t_bool status);
void	do_ra(t_stack **a_stack, t_bool status);
void	do_rra(t_stack **a_stack, t_bool status);

void	do_sb(t_stack **b_stack, t_bool status);
void	do_pb(t_stack **a_stack, t_stack **b_stack, t_bool status);
void	do_rb(t_stack **b_stack, t_bool status);
void	do_rrb(t_stack **b_stack, t_bool status);

void	do_ss(t_stack **a_stack, t_stack **b_stack, t_bool status);
void	do_rr(t_stack **a_stack, t_stack **b_stack, t_bool status);
void	do_rrr(t_stack **a_stack, t_stack **b_stack, t_bool status);

//sort
void	doSort(t_stack **a_stack);
void	doSmallSort(t_stack **a);
void	doFinalSort(t_stack **a_stack);

t_bool	doParamsCalculation(t_stack **stack, t_params *params, int size);

//quick sort
void	doQuickSort(int *arr, int low, int high);

#endif
