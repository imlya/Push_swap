/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:31 by imatek            #+#    #+#             */
/*   Updated: 2024/07/02 18:10:53 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_prev_last(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (temp->next->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = ft_prev_last(*lst);
	last = ft_lstlast(*lst);
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	reverse_rotate_a(t_list **a, int flag)
{
	reverse_rotate(a);
	if (flag)
		write(1, "rra\n", 3);
}

void	reverse_rotate_b(t_list **b, int flag)
{
	reverse_rotate(b);
	if (flag)
		write(1, "rrb\n", 3);
}

void	reverse_rotate_rrr(t_list **a, t_list **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (flag)
		write(1, "rrr\n", 3);
}
