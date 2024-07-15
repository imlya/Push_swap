/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:24:23 by imatek            #+#    #+#             */
/*   Updated: 2024/07/15 15:34:44 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_top_ofa(t_list **a)
// {
// }

// void	ft_top_ofb(t_list **b)
// {
// }

void	ft_cost(t_list **lst)
{
	int		lst_size;
	int		middle;
	t_list	*tmp;

	tmp = *lst;
	lst_size = ft_lstsize(*lst);
	middle = lst_size / 2;
	while (tmp)
	{
		if (tmp->position <= middle)
			tmp->cost = tmp->position;
		else
			tmp->cost = (lst_size - tmp->position) + 1;
		tmp = tmp->next;
	}
}

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
