/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:52:26 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 23:40:32 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_set_groups(t_list **lst)
// {
// 	t_list	*current;
// 	int		len;

// 	current = *lst;
// 	len = ft_lstsize(*lst);
// 	while (current)
// 	{
// 		if (current->index <= (len / 4))
// 			current->group = 1;
// 		else if (current->index <= (len / 4) * 2)
// 			current->group = 2;
// 		else if (current->index <= (len / 4) * 3)
// 			current->group = 3;
// 		else
// 			current->group = 4;
// 		current = current->next;
// 	}
// }

void	ft_set_groups(t_list **lst)
{
	t_list	*current;
	int		len;

	current = *lst;
	len = ft_lstsize(*lst);
	while (current)
	{
		if (current->index <= (len / 6))
			current->group = 1;
		else if (current->index <= (len / 6) * 2)
			current->group = 2;
		else if (current->index <= (len / 6) * 3)
			current->group = 3;
		else if (current->index <= (len / 6) * 4)
			current->group = 4;
		else if (current->index <= (len / 6) * 5)
			current->group = 5;
		else
			current->group = 6;
		current = current->next;
	}
}

int	ft_check_group(t_list **a, int group)
{
	t_list	*temp;

	temp = *a;
	// printf("group = %d\n", group);
	while (temp)
	{
		if (temp->group == group)
			return(1);
		temp = temp->next;
	}
	return (0);
}

void	ft_push_groups(t_list **a, t_list **b)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = *a;
	while (ft_lstsize(*a) > 3 && i <= 5)
	{
		while (ft_check_group(a, i) && ft_check_group(a, i + 1) && ft_lstsize(*a) > 3)
		{
			// printf("a->group = %d\n", (*a)->group);
			if ((*a)->group == i || (*a)->group == (i + 1))
			{
				ft_pb(b, a, 1);
				// printf("ok\n");
				// printf("b->group = %d\n", (*b)->group);
				if (((*b)->group == i + 1 && ft_lstsize(*b) >= 2)
					&& ((*a)->group >= i + 2))
					ft_rr(a, b, 1);
				else if ((*b)->group == i + 1 && ft_lstsize(*b) >= 2)
					ft_rb(b, 1);
				// printf("pas ok\n");
			}
			else
				ft_ra(a, 1);
		}
		// printf("here\n");
		i += 2;
	}
	while (ft_lstsize(*a) > 3)
		ft_pb(b, a, 1);
}
