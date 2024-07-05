/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/05 15:02:04 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(t_list **a)
{
	t_list	*current;
	t_list	*second;

	current = *a;
	while (current)
	{
		second = current->next;
		while (second)
		{
			if (ft_strcmp(current->temp, second->temp))
				second = second->next;
			else
				return (1);
		}
		current = current->next;
	}
	return (0);
}

int	ft_check_digits(t_list **a)
{
	t_list	*current;
	int		i;

	current = *a;
	while (current)
	{
		i = 0;
		while (current->temp[i])
		{
			if (!ft_isdigit(current->temp[i]))
				return (0);
			i++;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_limits(t_list **a)
{
	t_list	*current;
	t_list	*temp;
	int		i;

	current = *a;
	while (current)
	{
		i = 0;
		while (current->temp[i])
		{
			if (ft_atol(temp) > INT_MAX || ft_atol(temp) < INT_MIN
				|| temp != ft_itoa(ft_atoi(temp)))
				return (1);
			i++;
		}
		current = current->next;
	}
	return (0);
}

void	ft_set_stacka(char **av, t_list **a)
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
			ft_lstaddback(a, ft_lstnew(ft_strdup(split[j])));
			j++;
		}
		ft_free_tab(split);
		i++;
	}
}

t_list	**ft_parse(char **av)
{
	t_list	*a;

	a = NULL;
	ft_set_stacka(av, &a);
	if (ft_check_double(a) || (ft_check_limits(a)) || !ft_check_digits(a))
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	return (&a);
}
