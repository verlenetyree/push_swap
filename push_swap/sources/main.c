/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:19:12 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/13 18:23:11 by vtyree           ###   ########.fr       */
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

void	print_stack2(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	// printf("----------\n");
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
		printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*joinARGV;

	if (argc > 1)
	{
		if (argc == 2)
		{
			joinARGV = ft_strjoin("push_swap ", argv[1]);
			argv = ft_split(joinARGV, ' ');
			free(joinARGV);
			argc = split_count(argv);
		}
		if (CheckIfValid(argc, argv) == false)
		{
			ft_putstr_fd("Error\n", 2);
			if (argv[0][0] == 'p')
				free_array(argv);
			return (-1);
		}

		a = StackInit(argc - 1, argv + 1);
		doSort(&a);
		//print_stack2(a);
		free_stack(a);
		if (argv[0][0] == 'p')
			free_array(argv);
	}
	return (0);
}
