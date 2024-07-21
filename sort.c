/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:41:46 by imatek            #+#    #+#             */
/*   Updated: 2024/07/21 18:00:50 by imatek           ###   ########.fr       */
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
	if ((*lst)->value < (*lst)->next->value
		&& (*lst)->next->value < (*lst)->next->next->value
		&& (*lst)->next->next->value > (*lst)->value)
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

void	ft_top_ofa(t_list **a, t_list *cheapest)
{
	int	middle;

	middle = ft_lstsize(*a) / 2;
	if (cheapest->position <= middle)
	{
		while (cheapest->position > 1)
		{
			ft_ra(a, 1);
			cheapest->position--;
		}
	}
	// else if (cheapest->position == middle) 
	// 	while (cheapest->position-- > 1) 
	// 		ft_ra(a, 1);
	else
	{
		while (cheapest->position <= ft_lstsize(*a))
		{
			ft_rra(a, 1);
			cheapest->position++;
		}
	}
}

void	ft_top_ofa_reverse(t_list **a, t_list *cheapest)
{
	int	middle;

	middle = ft_lstsize(*a) / 2;
	if (cheapest->target->position <= middle)
	{
		while (cheapest->target->position > 1)
		{
			ft_ra(a, 1);
			cheapest->target->position--;
		}
	}
	else
	{
		while (cheapest->target->position <= ft_lstsize(*a))
		{
			ft_rra(a, 1);
			cheapest->target->position++;
		}
	}
}

void	ft_top_ofb(t_list **b, t_list *cheapest)
{
	int	middle;

	middle = ft_lstsize(*b) / 2;
	if (cheapest->target->position <= middle)
	{
		while (cheapest->target->position > 1)
		{
			ft_rb(b, 1);
			cheapest->target->position--;
		}
	}
	// else if (cheapest->position == middle) 
	// 	while (cheapest->position-- > 1) 
	// 		ft_rb(b, 1);
	else
	{
		while (cheapest->target->position <= ft_lstsize(*b))
		{
			ft_rrb(b, 1);
			cheapest->target->position++;
		}
	}
}

void	ft_top_ofb_reverse(t_list **b, t_list *cheapest)
{
	int	middle;

	middle = ft_lstsize(*b) / 2;
	if (cheapest->position <= middle)
	{
		while (cheapest->position > 1)
		{
			ft_rb(b, 1);
			cheapest->position--;
		}
	}
	else
	{
		while (cheapest->position <= ft_lstsize(*b))
		{
			ft_rrb(b, 1);
			cheapest->position++;
		}
	}
}

void	ft_top_final(t_list **lst, t_list *node)
{
	int	middle;

	middle = ft_lstsize(*lst) / 2;
	if (node->position <= middle)
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
