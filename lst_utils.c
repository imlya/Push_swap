/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:43:27 by imatek            #+#    #+#             */
/*   Updated: 2024/07/15 12:38:35 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(char *temp)
{
	t_list	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		return (NULL);
	new->value = ft_atoi(temp);
	new->position = 0;
	new->cost = 0;
	new->temp = temp;
	new->next = NULL;
	new->target = NULL;
	return (new);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*lst_bis;

	lst_bis = *lst;
	while (lst_bis)
	{
		temp = lst_bis->next;
		free(lst_bis->temp);
		free(lst_bis);
		lst_bis = temp;
	}
	*lst = NULL;
}

t_list	*ft_lst_prev_last(t_list *lst)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}
