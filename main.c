/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:10:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/15 15:47:03 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		lst_size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_parse(av, &stack_a))
	{
		ft_lstclear(&stack_a);
		exit(EXIT_FAILURE);
	}
	if (!ft_already_sorted(&stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	ft_set_position(&stack_a);
	lst_size = ft_lstsize(stack_a);
	if (lst_size == 3)
		ft_sort3(&stack_a);
	// ft_cost(&stack_a);
	ft_print(stack_a);
	// ft_push_swap(&stack_a, &stack_b);
	// printf("\n\n");
	// printf("\n\n");
	// ft_sort3(&stack_a);
	// printf("STACK A\n");
	// ft_print(stack_a);
	// printf("\n\n");
	// printf("STACK B\n");
	// ft_print(stack_b);
	return (0);
}

// void	ft_push_swap(t_list **a, t_list **b)
// {
// 	if (ft_lstsize(a) == 3)
// 	{
// 		ft_sort3(a);
// 		return ;
// 	}
// 	ft_pb(b, a, 1);
// 	ft_pb(b, a, 1);
// }
