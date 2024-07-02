/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:41 by imatek            #+#    #+#             */
/*   Updated: 2024/07/02 18:28:31 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				valeur;
	int				position;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

void	push(t_list **lst1, t_list **lst2);
void	push_a(t_list **a, t_list **b, int flag);
void	push_b(t_list **b, t_list **a, int flag);
t_list	*ft_prev_last(t_list *lst);
void	reverse_rotate(t_list **lst);
void	reverse_rotate_a(t_list **a, int flag);
void	reverse_rotate_b(t_list **b, int flag);
void	reverse_rotate_rrr(t_list **a, t_list **b, int flag);
void	rotate(t_list **lst);
void	rotate_a(t_list **a, int flag);
void	rotate_b(t_list **b, int flag);
void	rotate_rr(t_list **a, t_list **b, int flag);
void	swap(t_list **lst);
void	swap_a(t_list **a, int flag);
void	swap_b(t_list **b, int flag);
void	swap_ss(t_list **a, t_list **b, int flag);
t_list	*ft_lstnew(int valeur, int position);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif