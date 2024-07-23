/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/23 17:02:56 by imatek           ###   ########.fr       */
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
			if (ft_atoi(current->temp) != ft_atoi(second->temp))
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
			if (i == 0 && (current->temp[i] == '-' || current->temp[i] == '+'))
				i++;
			if (current->temp[i] && !ft_isdigit(current->temp[i]))
				return (0);
			if (current->temp[i])
				i++;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_limits(t_list **a)
{
	t_list	*current;
	char	*itoa;

	current = *a;
	while (current)
	{
		itoa = ft_itoa(ft_atol(current->temp));
		if (ft_atol(current->temp) > INT_MAX || ft_atol(current->temp) < INT_MIN
			|| ft_strncmp(current->temp, itoa, ft_strlen(current->temp)))
			return (free(itoa), 1);
		free(itoa);
		current = current->next;
	}
	return (0);
}

int	ft_parse(char **av, t_list **a)
{
	ft_init_stacka(av, a);
	if ((ft_check_limits(a)) || ft_check_double(a) || !ft_check_digits(a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}
