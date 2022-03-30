/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:03:44 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:07:01 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/array.h"
#include "../includes/stack.h"

int	array_have_duplicate(int *array, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (nb - 1))
	{
		j = (i + 1);
		while (j < nb)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	list_is_sort(t_stack *stack, int nb)
{
	int		i;
	t_stack	*t;

	i = 0;
	t = stack;
	while (i < (nb - 1))
	{
		if (t->value > (t->next)->value)
			return (0);
		i++;
		t = t->next;
	}
	return (1);
}

int	array_is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	if ((size) == 1)
		return (1);
	while (i < (size - 1))
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_num_len(int n)
{
	size_t	i;
	int		nn;
	int		count;

	if (n < 0)
		nn = -n;
	else
		nn = n;
	i = 0;
	while (nn >= 10)
	{
		nn = nn / 10;
		i++;
	}
	i++;
	if (n < 0)
		count = (i + 1);
	else
		count = (i);
	return (count);
}
