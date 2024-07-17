/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:18:03 by imatek            #+#    #+#             */
/*   Updated: 2024/07/17 21:01:20 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_top(t_list **, t_list **lst)
// {
//     int middle;

//     middle = ft_lstsize(lst) / 2;
//     if(temp->value < middle)
// }

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

t_list	*ft_cheapest(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*cheapest;
	int		cheapest_cost;
	int 	current_cost;

	current = *a;
	cheapest = current;
	cheapest_cost = cheapest->cost + cheapest->target->cost;
	printf("cheapest_cost %d\n", cheapest_cost);
	current = current->next;
	while (current)
	{
		current_cost = current->cost + current->target->cost;
		printf("current_cost %d\n", current_cost);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = current;
			printf("cheapest_cost %d\n", cheapest_cost);
			printf("current_cost %d\n", current_cost);
			printf("current %p\n", current);
		}
		current = current->next;
	}
	return (cheapest);
	printf("current %p\n", current);
}
