/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:47:07 by imatek            #+#    #+#             */
/*   Updated: 2024/07/26 19:05:46 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_btoa(t_list **a, t_list **b)
{
	t_list	*cheapest;

	while (*b)
	{
		ft_set_position(a);
		ft_set_position(b);
		ft_cost(a);
		ft_cost(b);
		ft_reset_target(b);
		ft_target(a, b);
		cheapest = ft_cheapest(b);
		ft_optimization(b, a, cheapest);
		ft_set_top('a', a, cheapest->target);
		ft_set_top('b', b, cheapest);
		ft_pa(a, b, 1);
	}
}

void	ft_push_swap(t_list **a, t_list **b)
{
	(void)b;
	if (!ft_already_sorted(a))
	{
		ft_lstclear(a);
		return ;
	}
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 1);
		return ;
	}
	if (ft_lstsize(*a) == 3)
	{
		ft_sort3(a);
		return ;
	}
	ft_sort_index(a);
	ft_set_groups(a);
	ft_push_groups(a, b);
	ft_sort3(a);
	ft_push_btoa(a, b);
	ft_set_top('a', a, ft_smallest(a));
}
