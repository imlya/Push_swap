/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:10:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/17 20:59:13 by imatek           ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	ft_push_swap(&stack_a, &stack_b);
	ft_cost(&stack_a);
	ft_print(stack_a);
	printf("\n\n");
	printf("\n\n");
	printf("STACK A\n");
	ft_print(stack_a);
	printf("\n\n");
	printf("STACK B\n");
	ft_print(stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac < 2)
// 		return (ft_putendl_fd("Error", 2), 0);
// 	if (ft_parse(av, &stack_a))
// 	{
// 		ft_lstclear(&stack_a);
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_pb(&b, &a, 1);
// 	ft_pb(&b, &a, 1);
// 	ft_target(&a , &b);
// 	ft_set_position(&a);
// 	ft_cost(&a);
// 	ft_print(a);
// 	ft_lstclear(&stack_a);
// 	ft_lstclear(&stack_b);
// 	return (0);
// }
