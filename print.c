/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:46 by imatek            #+#    #+#             */
/*   Updated: 2024/07/17 20:58:38 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_list *a)
{
	t_list	*temp_a;
	int		i;

	temp_a = a;
	i = 1;
	while (temp_a)
	{
		printf("NOEUD %d\n", i);
		printf("value %d\n", temp_a->value);
		printf("position %d\n", temp_a->position);
		printf("cost %d\n", temp_a->cost);
		printf("temp %s\n", temp_a->temp);
		if (temp_a->target)
			printf("target->value %d\n\n", temp_a->target->value);
		else
			printf("\n");
		i++;
		temp_a = temp_a->next;
	}
}

// void	ft_print(t_list *a)
// {
// 	t_list	*tmp;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		printf("value %d\n", tmp->value);
// 		printf("position %d\n", tmp->position);
// 		printf("cost %d\n", tmp->cost);
// 		printf("temp %s\n", tmp->temp);
// 		if(tmp->target)
// 			printf("target %d\n\n", tmp->target->value);
// 		tmp = tmp->next;
// 	}
// }
