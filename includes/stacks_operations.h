/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:55:37 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 15:05:58 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_OPERATIONS_H
# define STACKS_OPERATIONS_H
# include "stack.h"

void	ft_swap(t_stack **stack, char c);
void	ft_both_swap(t_stack **sta, t_stack **stb);
void	ft_push_to_other_stack(t_stack **st1, t_stack **st2, char c);
t_stack	*ft_get_last_node(t_stack *stack);
void	ft_shift_up(t_stack **stack, char c);
void	ft_both_shift_up(t_stack **sta, t_stack **stb);
void	ft_shift_down(t_stack **stack, char c);
void	ft_both_shift_down(t_stack **sta, t_stack **stb);

#endif
