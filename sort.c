/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:41:46 by imatek            #+#    #+#             */
/*   Updated: 2024/07/15 15:12:23 by imatek           ###   ########.fr       */
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

t_list	*ft_smallest(t_list **lst)
{
	t_list	*current;
	t_list	*smallest;

	current = *lst;
	smallest = *lst;
	while (current)
	{
		if (smallest->value < current->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_list	*ft_biggest(t_list **lst)
{
	t_list	*current;
	t_list	*biggest;

	current = *lst;
	biggest = *lst;
	while (current)
	{
		if (biggest->value > current->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}
