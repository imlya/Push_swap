/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:41 by imatek            #+#    #+#             */
/*   Updated: 2024/07/09 17:08:52 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!*lst2)
		return ;
	temp = (*lst2)->next;
	ft_lstadd_front(lst1, *lst2);
	*lst2 = temp;
}

void	ft_pa(t_list **a, t_list **b, int flag)
{
	ft_push(a, b);
	if (flag)
		write(1, "pa\n", 3);
}

void	ft_pb(t_list **b, t_list **a, int flag)
{
	ft_push(b, a);
	if (flag)
		write(1, "pb\n", 3);
}
