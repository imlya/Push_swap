/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:10:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/11 22:58:08 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_parse(av, &stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	if (ft_already_sorted(&stack_a))
	{
		ft_lstclear(a);
		return ;
	}
	// ft_push_swap(&stack_a, &stack_b);
	// ft_print(stack_a);
	// printf("\n\n");
	// printf("\n\n");
	// printf("STACK A\n");
	// ft_print(stack_a);
	// printf("\n\n");
	// printf("STACK B\n");
	// ft_print(stack_b);
	return (0);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	if (ft_lstsize(a) == 3)
	{
		ft_sort3(a);
		return ;
	}
	ft_pb(b, a, 1);
	ft_pb(b, a, 1);
}
