/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:49:17 by imatek            #+#    #+#             */
/*   Updated: 2024/07/29 12:23:38 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **a, t_list **b, char *line)
{
	free(line);
	if (*a)
		ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	get_next_line(0, 1);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_linecmp(t_list **a, t_list **b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		ft_pa(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pb(b, a, 0);
	else if (!ft_strcmp(line, "sa\n"))
		ft_sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(a, b, 0);
	else
		ft_error(a, b, line);
}

void	ft_checker(t_list **a)
{
	t_list	*b;
	char	*line;

	b = NULL;
	line = get_next_line(0, 0);
	while (line)
	{
		ft_linecmp(a, &b, line);
		free(line);
		line = get_next_line(0, 0);
	}
	free(line);
	if (ft_already_sorted(a) && !b)
		ft_putendl_fd("OK", 2);
	else
		ft_putendl_fd("KO", 2);
	if (b)
		ft_lstclear(&b);
}

int	main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac < 2)
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_parse(av, &a))
	{
		ft_lstclear(&a);
		exit(EXIT_FAILURE);
	}
	if (!a)
	{
		ft_lstclear(&a);
		exit(EXIT_FAILURE);
	}
	ft_checker(&a);
	ft_lstclear(&a);
	return (0);
}
