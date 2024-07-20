/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:45:02 by imatek            #+#    #+#             */
/*   Updated: 2024/07/20 16:01:51 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stacka(char **av, t_list **a)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			ft_lstadd_back(a, ft_lstnew(ft_strdup(split[j])));
			j++;
		}
		ft_free_tab(split);
		i++;
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

void	ft_target(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *a;
	temp_a->target = ft_smallest(b);
	while (temp_a)
	{
		temp_b = *b;
		while (temp_b)
		{
			if (ft_is_smallest(temp_a, b) || ft_is_biggest(temp_a, b))
				temp_a->target = ft_biggest(b);
			// else if (ft_is_biggest(temp_a, b))
			// 	temp_a->target = ft_smallest(b);
			else if (!temp_a->target && temp_b->value > temp_a->value)
				temp_a->target = temp_b;
			else if (temp_a->target && temp_a->value > temp_b->value
				&& temp_b->value > temp_a->target->value)
				temp_a->target = temp_b;
			// else if (!temp_a->target)
			// 	temp_a->target = temp_b;
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
}

void	ft_target_reverse(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_b = *b;
	temp_b->target = ft_biggest(a);
	while (temp_b)
	{
		temp_a = *a;
		while (temp_a)
		{
			if (ft_is_smallest(temp_b, a) || ft_is_biggest(temp_b, a))
				temp_b->target = ft_smallest(a);
			// else if (ft_is_biggest(temp_a, b))
			// 	temp_a->target = ft_smallest(b);
			else if (!temp_b->target && temp_b->value > temp_a->value)
				temp_b->target = temp_a;
			else if (temp_b->target && temp_a->value > temp_b->value
				&& temp_a->value < temp_b->target->value)
				temp_b->target = temp_a;
			// else if (!temp_a->target)
			// 	temp_a->target = temp_b;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}
