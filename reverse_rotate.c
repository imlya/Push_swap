/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:31 by imatek            #+#    #+#             */
/*   Updated: 2024/07/15 12:56:01 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = ft_lst_prev_last(*lst);
	last = ft_lstlast(*lst);
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	ft_rra(t_list **a, int flag)
{
	ft_reverse_rotate(a);
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b, int flag)
{
	ft_reverse_rotate(b);
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b, int flag)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	if (flag)
		write(1, "rrr\n", 4);
}
