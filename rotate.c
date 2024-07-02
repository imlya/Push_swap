/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:38:52 by imatek            #+#    #+#             */
/*   Updated: 2024/07/02 17:30:25 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = temp;
}

void	rotate_a(t_list **a, int flag)
{
	rotate(a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int flag)
{
	rotate(b);
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_list **a, t_list **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag)
		write(1, "rr\n", 3);
}
