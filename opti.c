/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:33:59 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 22:27:39 by imatek           ###   ########.fr       */
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
