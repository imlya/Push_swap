/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:43:27 by imatek            #+#    #+#             */
/*   Updated: 2024/07/09 17:38:27 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*ft_lstnew(int valeur, int position)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(struct s_list));
// 	if (!new)
// 		return (NULL);
// 	new->valeur = valeur;
// 	new->position = position;
// 	new->next = NULL;
// 	return (new);
// }

t_list	*ft_lstnew(char *temp)
{
	t_list	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		return (NULL);
	new->valeur = 0;
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

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
