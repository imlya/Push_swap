/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:24:23 by imatek            #+#    #+#             */
/*   Updated: 2024/07/17 14:18:26 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_top_ofa(t_list **a)
// {
// }

// void	ft_top_ofb(t_list **b)
// {
// }

t_list	*ft_smallest(t_list **lst)
{
	t_list	*current;
	t_list	*smallest;

	current = *lst;
	smallest = *lst;
	while (current)
	{
		if (smallest->value > current->value)
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
		if (biggest->value < current->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

int ft_is_smallest(t_list *smallest, t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (smallest->value > current->value)
			return (0);
		current = current->next;
	}
	return (1);
} 

int ft_is_biggest(t_list *biggest, t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (biggest->value < current->value)
			return (0);
		current = current->next;
	}
	return (1);
} 
