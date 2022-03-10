/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:34:08 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 05:32:07 by margaritaso      ###   ########.fr       */
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
}	t_stack;

// utils
int		split_count(char **arr);
void	free_array(char **arr);

t_bool 	CheckIfValid(int argc, char **argv);

t_stack	*StackInit(int argc,char **argv);

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

#endif
