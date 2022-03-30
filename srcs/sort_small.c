/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:06:38 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/28 14:53:32 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks_operations.h"
#include "../includes/sort.h"

void	sort3(t_stack **a)
{
	if (((*a)->value > (*a)->next->value)
		&& (*a)->value < (*a)->next->next->value)
		ft_swap(a, 'a');
	else if (((*a)->value > (*a)->next->value)
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ft_swap(a, 'a');
		ft_shift_down(a, 'a');
	}
	else if (((*a)->value > (*a)->next->value)
		&& (*a)->next->value < (*a)->next->next->value)
		ft_shift_up(a, 'a');
	else if (((*a)->value < (*a)->next->value)
		&& (*a)->value > (*a)->next->next->value)
		ft_shift_down(a, 'a');
	else if (((*a)->value < (*a)->next->value)
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ft_swap(a, 'a');
		ft_shift_up(a, 'a');
	}
}

void	sort5(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*b) < 2)
	{
		if ((*a)->value == 0 || (*a)->value == 4)
			ft_push_to_other_stack(a, b, 'b');
		else
			ft_shift_up(a, 'a');
	}
	sort3(a);
	ft_push_to_other_stack(b, a, 'a');
	ft_push_to_other_stack(b, a, 'a');
	if ((*a)->value == 4)
		ft_shift_up(a, 'a');
	else
	{
		ft_swap(a, 'a');
		ft_shift_up(a, 'a');
	}
}

void	algo_parser(t_stack **a, t_stack **b, int nb)
{
	if (nb == 3)
		sort3(a);
	else if (nb == 5)
		sort5(a, b);
	else
		radix_sort(a, b);
}
