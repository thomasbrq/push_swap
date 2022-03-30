/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:54:53 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:33:23 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks_operations.h"

/*
 * Swap the two first elements at the top of the stack.
*/

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*a;
	t_stack	*a2;
	t_stack	*temp;

	temp = *stack;
	if (!temp || !temp->next)
		return ;
	a = temp->next;
	a2 = temp->next->next;
	temp->next = a2;
	a->next = temp;
	*stack = a;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

/*
 * Swap the two first elements in the two stacks.
*/

void	ft_both_swap(t_stack **sta, t_stack **stb)
{
	ft_swap(sta, 'c');
	ft_swap(stb, 'c');
	ft_printf("ss\n");
}

/*
 * Push from st1 to st2
 * c = direction
*/

void	ft_push_to_other_stack(t_stack **st1, t_stack **st2, char c)
{
	t_stack	*t;

	t = *st1;
	*st2 = stack_push(*st2, t->value);
	stack_pop(st1);
	t = NULL;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

/*
 * Get the last node of the stack.
*/

t_stack	*ft_get_last_node(t_stack *stack)
{
	int	i;

	if (!stack)
		return (stack);
	i = 0;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

/*
 * Shift up all elements of stack by 1.
 * c = direction
*/

void	ft_shift_up(t_stack **stack, char c)
{
	t_stack	*s;
	t_stack	*temp;
	t_stack	*temp2;

	s = *stack;
	if (!s || !s->next)
		return ;
	temp = *stack;
	temp = ft_get_last_node(temp);
	temp2 = s->next;
	s->next = NULL;
	temp->next = s;
	*stack = temp2;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}
