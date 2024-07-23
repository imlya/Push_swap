/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:33:59 by imatek            #+#    #+#             */
/*   Updated: 2024/07/23 23:27:11 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimization(t_list **a, t_list **b, t_list *cheapest)
{
	if (ft_position(a, cheapest) && ft_position(b, cheapest->target))
	{
		while (cheapest != *a && cheapest->target != *b)
			ft_rr(a, b, 1);
	}
	else if (!ft_position(a, cheapest) && !ft_position(b, cheapest->target))
	{
		while (cheapest != *a && cheapest->target != *b)
			ft_rrr(a, b, 1);
	}
}

void	ft_optimization_reverse(t_list **b, t_list **a, t_list *cheapest)
{
	if (ft_position(b, cheapest) && ft_position(a, cheapest->target))
	{
		while (cheapest != *b && cheapest->target != *a)
			ft_rr(a, b, 1);
	}
	else if (!ft_position(b, cheapest) && !ft_position(a, cheapest->target))
	{
		while (cheapest != *b && cheapest->target != *a)
			ft_rrr(a, b, 1);
	}
}

// void	ft_optimized_push(t_list *node, t_list **a, t_list **b)
// {
// 	int	middle_a;
// 	int	middle_b;

// 	middle_a = ft_lst_size(a) / 2;
// 	middle_b = ft_lst_size(b) / 2;
// 	if (node->target->position > middle_b && node->position > middle_a)
// 	{
// 		ft_optimization(a, b, cheapest);
// 	}
// 	else if (node->target->position <= middle_b
// 		&& node->position <= middle_a)
// 	{
// 		ft_optimization_reverse(a, b);
// 	}
// 	else
// 	{
// 		ft_set_top('a', a, node);
// 		ft_set_top('a', b, node->target);
// 	}
// }
