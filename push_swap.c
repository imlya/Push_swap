/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:47:07 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 23:36:36 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_atob(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	while (ft_lstsize(*stack_a) > 3)
	{
		ft_set_position(stack_a);
		ft_set_position(stack_b);
		ft_cost(stack_a);
		ft_cost(stack_b);
		ft_reset_target(stack_a);
		// ft_set_groups(stack_a);
		// ft_push_groups(stack_a, stack_b);
		// ft_target(stack_a, stack_b);
		cheapest = ft_cheapest(stack_a);
		ft_optimization(stack_a, stack_b, cheapest);
		ft_set_top('a', stack_a, cheapest);
		ft_set_top('b', stack_b, cheapest->target);
		ft_pb(stack_b, stack_a, 1);
	}
}

void	ft_push_btoa(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	while (*stack_b)
	{
		ft_set_position(stack_a);
		ft_set_position(stack_b);
		ft_cost(stack_a);
		ft_cost(stack_b);
		ft_reset_target(stack_b);
		ft_target_reverse(stack_a, stack_b);
		cheapest = ft_cheapest(stack_b);
		ft_optimization(stack_b, stack_a, cheapest);
		// ft_optimization_reverse(stack_b, stack_a, cheapest);
		ft_set_top('a', stack_a, cheapest->target);
		ft_set_top('b', stack_b, cheapest);
		ft_pa(stack_a, stack_b, 1);
	}
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (!ft_already_sorted(stack_a))
	{
		ft_lstclear(stack_a);
		return ;
	}
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a, 1);
		return ;
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		ft_sort3(stack_a);
		return ;
	}
	ft_sort_index(stack_a);
	ft_set_groups(stack_a);
	// ft_set_groups(stack_b);
	// printf("STACK A\n");
	// ft_print(*stack_a);
	ft_push_groups(stack_a, stack_b);
	ft_sort3(stack_a);
	// ft_set_position(stack_a);
	// ft_set_position(stack_b);
	// ft_cost(stack_a);
	// ft_cost(stack_b);
	// ft_target_reverse(stack_a, stack_b);
	// printf("STACK A\n");
	// ft_print(*stack_a);
	// printf("STACK B\n");
	// ft_print(*stack_b);
	ft_push_btoa(stack_a, stack_b);
	ft_set_top('a', stack_a, ft_smallest(stack_a));
}
