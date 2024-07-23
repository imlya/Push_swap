/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:04:32 by imatek            #+#    #+#             */
/*   Updated: 2024/07/23 19:26:26 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position(t_list **lst, t_list *node)
{
	int	middle;

	middle = (ft_lstsize(*lst) / 2) + 1;
	if (ft_lstsize(*lst) % 2 == 0)
		middle = ft_lstsize(*lst) / 2;
	if (node->position <= middle)
		return (1);
	else
		return (0);
}

void	ft_set_top(char list, t_list **lst, t_list *cheapest)
{
	if (ft_position(lst, cheapest))
	{
		while (cheapest->position > 1)
		{
			if (list == 'a')
				ft_ra(lst, 1);
			else if (list == 'b')
				ft_rb(lst, 1);
			cheapest->position--;
		}
	}
	else
	{
		while (cheapest->position <= ft_lstsize(*lst))
		{
			if (list == 'a')
				ft_rra(lst, 1);
			else if (list == 'b')
				ft_rrb(lst, 1);
			cheapest->position++;
		}
	}
}

void	ft_set_top_target(char list, t_list **lst, t_list *cheapest)
{
	if (ft_position(lst, cheapest->target))
	{
		while (cheapest->target->position > 1)
		{
			if (list == 'a')
				ft_ra(lst, 1);
			else if (list == 'b')
				ft_rb(lst, 1);
			cheapest->target->position--;
		}
	}
	else
	{
		while (cheapest->target->position <= ft_lstsize(*lst))
		{
			if (list == 'a')
				ft_rra(lst, 1);
			else if (list == 'b')
				ft_rrb(lst, 1);
			cheapest->target->position++;
		}
	}
}

void	ft_top_final(t_list **lst, t_list *node)
{
	if (ft_position(lst, node))
	{
		while (*lst != node)
		{
			ft_ra(lst, 1);
			node->position--;
		}
	}
	else
	{
		while (*lst != node)
		{
			ft_rra(lst, 1);
			node->position++;
		}
	}
}
