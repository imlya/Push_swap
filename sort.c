/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:41:46 by imatek            #+#    #+#             */
/*   Updated: 2024/07/26 16:29:44 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sorted(t_list **a)
{
	t_list	*current;

	current = *a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_sort3(t_list **lst)
{
	if (!ft_already_sorted(lst))
		return (0);
	else if ((*lst)->value < (*lst)->next->value
		&& (*lst)->next->value > (*lst)->next->next->value
		&& (*lst)->next->next->value > (*lst)->value)
		return (ft_rra(lst, 1), ft_sa(lst, 1), 0);
	else if ((*lst)->value > (*lst)->next->value
		&& (*lst)->next->value < (*lst)->next->next->value
		&& (*lst)->next->next->value > (*lst)->value)
		return (ft_sa(lst, 1), 0);
	else if ((*lst)->value < (*lst)->next->value
		&& (*lst)->next->value > (*lst)->next->next->value
		&& (*lst)->next->next->value < (*lst)->value)
		return (ft_rra(lst, 1), 0);
	else if ((*lst)->value > (*lst)->next->value
		&& (*lst)->next->value > (*lst)->next->next->value
		&& (*lst)->next->next->value < (*lst)->value)
		return (ft_ra(lst, 1), ft_sa(lst, 1), 0);
	else if ((*lst)->value > (*lst)->next->value
		&& (*lst)->next->value < (*lst)->next->next->value
		&& (*lst)->next->next->value < (*lst)->value)
		return (ft_ra(lst, 1), 0);
	return (0);
}

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

void	ft_set_top(char list, t_list **lst, t_list *node)
{
	if (ft_position(lst, node))
	{
		while (node != *lst)
		{
			if (list == 'a')
				ft_ra(lst, 1);
			else if (list == 'b')
				ft_rb(lst, 1);
		}
	}
	else
	{
		while (node != *lst)
		{
			if (list == 'a')
				ft_rra(lst, 1);
			else if (list == 'b')
				ft_rrb(lst, 1);
		}
	}
}

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
