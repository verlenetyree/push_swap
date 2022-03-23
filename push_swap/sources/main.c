/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:19:12 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/23 20:13:38 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		free_stack(a);
		if (argv[0][0] == 'p')
			free_array(argv);
	}
	return (0);
}
