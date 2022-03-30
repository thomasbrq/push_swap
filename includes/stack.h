/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:43:03 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:05:05 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_push(t_stack *stack, int value);
void	stack_pop(t_stack **stack);
t_stack	*stack_fill(t_stack *stack, int *array, int nb_args);
void	stack_free(t_stack **stack);
int		ft_lstsize(t_stack *lst);

#endif
