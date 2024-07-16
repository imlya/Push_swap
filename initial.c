/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:45:02 by imatek            #+#    #+#             */
/*   Updated: 2024/07/16 19:31:42 by imatek           ###   ########.fr       */
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
			tmp->cost = tmp->position - 1;
		else
			tmp->cost = (lst_size - tmp->position) + 1;
		tmp = tmp->next;
	}
}

void	ft_target(t_list **a, t_list **b)
{
	t_list *temp_a;
	t_list	*temp_b;
	t_list	*min;
	
	temp_a = *a;
	min = ft_smallest(b);
	while (temp_a)
	{
		temp_b = *b;
		while (temp_b)
		{
			if ((ft_is_smallest(temp_a, a) && ft_is_smallest(temp_a, b)) || ft_is_biggest(temp_a, b))
				temp_a->target = ft_biggest(b);
			else if (!temp_a->target && temp_b->value < temp_a->value)
				temp_a->target = temp_b;
			else if (temp_a->target && temp_a->target->value < temp_b->value && temp_b->value < temp_a->value)
				temp_a->target = temp_b;
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
}
