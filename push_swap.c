/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:47:07 by imatek            #+#    #+#             */
/*   Updated: 2024/07/17 21:00:40 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_swap(t_list **stack_a, t_list **stack_b)
{
    if (!ft_already_sorted(stack_a))
	{
		ft_lstclear(stack_a);
		return ;
	}
	if(ft_lstsize(*stack_a) == 2)
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
	ft_pb(stack_b, stack_a, 1);
	ft_pb(stack_b, stack_a, 1);
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_sb(stack_b, 1);
	ft_target(stack_a, stack_b);
	ft_cheapest(stack_a, stack_b);
	printf("STACK A\n\n\n");
	ft_print(*stack_a);
	printf("STACK B\n\n\n");
	ft_print(*stack_b);
	while (ft_lstsize(*stack_a) > 0)
	{
		ft_set_position(stack_a);
		ft_target(stack_a, stack_b);
		ft_cost(stack_a);
		ft_cost(stack_b);
		ft_pb(stack_b, stack_a, 1);
	}
	ft_set_position(stack_b);
	ft_cost(stack_b);
	printf("STACK A\n\n\n");
	ft_print(*stack_a);
	printf("STACK B\n\n\n");
	ft_print(*stack_b);
}

