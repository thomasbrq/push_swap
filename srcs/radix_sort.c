/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:01:15 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:30:24 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks_operations.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		max_bits;

	temp = *stack;
	max = temp->value;
	max_bits = 0;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		tmp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			tmp = (*stack_a)->value;
			if (((tmp >> i) & 1) == 1)
				ft_shift_up(stack_a, 'a');
			else
				ft_push_to_other_stack(stack_a, stack_b, 'b');
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_push_to_other_stack(stack_b, stack_a, 'a');
		i++;
	}
}

int	*sort_array(int *array, int nb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < (nb - 1))
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (array);
}

int	*copy_array(int *array, int *temp, int nb)
{
	int	i;

	i = -1;
	temp = (int *) malloc(nb * sizeof(int));
	if (!temp)
		return (NULL);
	while (++i < nb)
		temp[i] = array[i];
	return (temp);
}

int	*simplify_array(int *array, int nb)
{
	int	*temp;
	int	i;
	int	j;

	temp = NULL;
	temp = copy_array(array, temp, nb);
	temp = sort_array(temp, nb);
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (array[i] == temp[j])
			{
				array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(temp);
	return (array);
}
