/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:39:17 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 14:42:41 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	algo_parser(t_stack **a, t_stack **b, int nb);
void	sort3(t_stack **a);
void	sort5(t_stack **a, t_stack **b);
int		list_is_sort(t_stack *stack, int nb);

#endif
