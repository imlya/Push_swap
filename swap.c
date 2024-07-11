/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:38:58 by imatek            #+#    #+#             */
/*   Updated: 2024/07/11 22:02:35 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*temp1;
	t_list	*temp2;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp1 = *lst;
	temp2 = temp1->next;
	if (ft_lstsize(*lst) > 2)
		temp1->next = temp2->next;
	else
		temp1->next = NULL;
	temp2->next = temp1;
	*lst = temp2;
}

void	ft_sa(t_list **a, int flag)
{
	ft_swap(a);
	if (flag)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **b, int flag)
{
	ft_swap(b);
	if (flag)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b, int flag)
{
	ft_swap(a);
	ft_swap(b);
	if (flag)
		write(1, "ss\n", 3);
}

//flag = 1 pour push_swap
//flag = 0 pour le checker bonus ne pas afficher sa