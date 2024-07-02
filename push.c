/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:41 by imatek            #+#    #+#             */
/*   Updated: 2024/07/02 17:50:52 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!*lst2)
		return ;
	temp = (*lst2)->next;
	ft_lstaddfront(lst1, *lst2);
	*lst2 = temp;
}

void	push_a(t_list **a, t_list **b, int flag)
{
	push(a, b);
	if (flag)
		write(1, "pa\n", 3);
}

void	push_b(t_list **b, t_list **a, int flag)
{
	push(b, a);
	if (flag)
		write(1, "pb\n", 3);
}
