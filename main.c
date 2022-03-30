/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:27:54 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 16:19:34 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @description : Sort numbers with two stacks
 * The stack 'a' contains a random amount of negative and/or positive
   numbers which cannot be duplicated.
 * The stack 'b' is empty.
*/

#include "includes/stacks_operations.h"
#include "includes/array.h"
#include "includes/sort.h"

static void	check_array(int **array, int nb)
{
	if (!*array || array_have_duplicate(*array, nb))
	{
		write(2, "Error\n", 6);
		if (*array)
			free(*array);
		exit(-1);
	}
	if (array_is_sorted(*array, nb))
	{
		free(*array);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		nb;
	int		*array;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(0);
	nb = 0;
	array = NULL;
	a = NULL;
	b = NULL;
	array = ft_get_params(argc, argv, array, &nb);
	check_array(&array, nb);
	array = simplify_array(array, nb);
	a = stack_fill(a, array, nb);
	algo_parser(&a, &b, nb);
	free(array);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
