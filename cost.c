/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:18:03 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 23:54:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_list **lst)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = 1;
	while (tmp)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_cost(t_list **lst)
{
	int		lst_size;
	int		middle;
	t_list	*tmp;

	tmp = *lst;
	lst_size = ft_lstsize(*lst);
	if (ft_lstsize(*lst) % 2 == 0)
		middle = lst_size / 2;
	else
		middle = (lst_size / 2) + 1;
	while (tmp)
	{
		if (tmp->position <= middle)
			tmp->cost = tmp->position - 1;
		else
			tmp->cost = (lst_size - tmp->position) + 1;
		tmp = tmp->next;
	}
}

t_list	*ft_cheapest(t_list **lst)
{
	t_list	*current;
	t_list	*cheapest;
	int		cheapest_cost;
	int		current_cost;

	current = *lst;
	cheapest = current;
	current = current->next;
	while (current)
	{
		cheapest_cost = cheapest->cost + cheapest->target->cost;
		current_cost = current->cost + current->target->cost;
		if (current_cost < cheapest_cost)
		{
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
