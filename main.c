/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:10:45 by imatek            #+#    #+#             */
/*   Updated: 2024/07/09 17:33:24 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if(ac < 2)
		return(ft_putendl_fd("Error", 2), 0);
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parse(av, &stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	ft_print(stack_a);
	printf("\n\n");
	ft_pb(&stack_b, &stack_a, 1);
	printf("\n\n");
	printf("STACK A\n");
	ft_print(stack_a);
	printf("\n\n");
	printf("STACK B\n");
	ft_print(stack_b);
	return (0);
}
