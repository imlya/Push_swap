/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:42:36 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 21:19:14 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_index(t_list *node1, t_list *node2)
{
	int	temp;

	temp = node1->index;
	node1->index = node2->index;
	node2->index = temp;
}

void	ft_set_index(t_list **lst)
{
	t_list	*current;
	int		index;

	index = 1;
	current = *lst;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void	ft_sort_index(t_list **lst)
{
	int		size;
	t_list	*current;
	t_list	*temp;

	size = ft_lstsize(*lst);
	ft_set_index(lst);
	while (size > 1)
	{
		current = *lst;
		while (current)
		{
			temp = *lst;
			while (temp)
			{
				if (temp->index > current->index
					&& temp->value < current->value)
					ft_swap_index(temp, current);
				temp = temp->next;
			}
			current = current->next;
		}
		size--;
	}
}
