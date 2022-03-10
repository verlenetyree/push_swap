/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:19:12 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/09 16:36:28 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_b()
{
	int		i = 0;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 3);
	while (i < 5)
	{
		arr[i] = (char *)malloc(sizeof(char) * 2);
		i++;
	}
	arr[0] = "10";
	arr[1] = "20";
	arr[2] = "30";
	arr[3] = "40";
	arr[4] = "50";
	return(StackInit(5, arr));
}

void	print_stack(t_stack *stack, char c)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
		printf("_\n%c\n\n", c);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*joinARGV;

	if (argc > 1)
	{
		if (argc == 2)
		{
			joinARGV = ft_strjoin(".push_swap ", argv[1]);
			argv = ft_split(joinARGV, ' ');
			free(joinARGV);
			argc = split_count(argv);
		}
		if (CheckIfValid(argc, argv) == false)
		{
			ft_putstr_fd("Error\n", 2);
			if (argv[0][0] == '.')
				free_array(argv);
			return (-1);
		}
		a = StackInit(argc - 1, argv + 1);
		DoSort(a);

		///////////////////////////////////
		// SA
		print_stack(a, 'a');

		do_sa(&a, false);
		printf("sa has done:\n\n");
		print_stack(a, 'a');

		///////////////////////////////////
		// PA
		t_stack *b;

		b = init_b();
		print_stack(b, 'b');

		printf("pa has done:\n\n");

		do_pa(&a, &b, false);
		print_stack(a, 'a');
		print_stack(b, 'b');

		///////////////////////////////////
		// SB
		do_sb(&b, false);
		printf("sb has done:\n\n");
		print_stack(b, 'b');

		///////////////////////////////////
		// PB
		do_pb(&a, &b, false);
		printf("pb has done:\n\n");
		print_stack(a, 'a');
		print_stack(b, 'b');

		///////////////////////////////////
		// RA
		do_ra(&a, false);
		printf("ra has done:\n\n");
		print_stack(a, 'a');

		///////////////////////////////////
		// RRA
		do_rra(&a, false);
		printf("rra has done:\n\n");
		print_stack(a, 'a');

		///////////////////////////////////
		// RB
		do_rb(&b, false);
		printf("rb has done:\n\n");
		print_stack(b, 'b');

		///////////////////////////////////
		// RRB
		do_rra(&b, false);
		printf("rrb has done:\n\n");
		print_stack(b, 'b');
	}
	return (0);
}
