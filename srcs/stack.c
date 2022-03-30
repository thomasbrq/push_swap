/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:32:47 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:33:12 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/*
 * @description Add a new 'int' element in the 'Stack'.
*/

t_stack	*stack_push(t_stack *stack, int value)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack *));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = stack;
	stack = new;
	return (stack);
}

/*
 * Remove the first element of the 'Stack'.
*/

void	stack_pop(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return ;
	*stack = (*stack)->next;
	temp->next = NULL;
	free(temp);
}

/*
 * Return the number of elements in list.
*/

int	ft_lstsize(t_stack *lst)
{
	int			i;
	t_stack		*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
 * Fill the stack with the array.
*/

t_stack	*stack_fill(t_stack *stack, int *array, int nb_args)
{
	if (!array || !nb_args)
		return (stack);
	nb_args = (nb_args - 1);
	while (nb_args >= 0)
	{
		stack = stack_push(stack, array[nb_args]);
		nb_args--;
	}
	return (stack);
}

/*
 * Free the stack
*/

void	stack_free(t_stack **stack)
{
	while (*stack)
		stack_pop(stack);
}
