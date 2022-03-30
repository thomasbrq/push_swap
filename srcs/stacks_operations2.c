/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:54:53 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 14:02:06 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks_operations.h"

/*
 * Shift up all elements in the two stacks.
*/

void	ft_both_shift_up(t_stack **sta, t_stack **stb)
{
	ft_shift_up(sta, 'c');
	ft_shift_up(stb, 'c');
	ft_printf("rr\n");
}

/*
 * Get the before last node in stack.
*/

static t_stack	*ft_get_before_last_node(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

/*
 * Shift down all elements in stack.
 * c = direction
*/

void	ft_shift_down(t_stack **stack, char c)
{
	t_stack	*s;
	t_stack	*temp;
	int		tvalue;

	s = *stack;
	if (!s || !s->next)
		return ;
	temp = *stack;
	temp = ft_get_before_last_node(temp);
	tvalue = temp->next->value;
	if (temp->next)
		free(temp->next);
	*stack = stack_push(*stack, tvalue);
	temp->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

/*
 * Shit down all elements in the two stacks.
*/

void	ft_both_shift_down(t_stack **sta, t_stack **stb)
{
	ft_shift_down(sta, 'c');
	ft_shift_down(stb, 'c');
	ft_printf("rrr\n");
}
