/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:38:52 by imatek            #+#    #+#             */
/*   Updated: 2024/07/05 16:22:16 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst)
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

void	ft_ra(t_list **a, int flag)
{
	ft_rotate(a);
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int flag)
{
	ft_rotate(b);
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b, int flag)
{
	ft_rotate(a);
	ft_rotate(b);
	if (flag)
		write(1, "rr\n", 3);
}
