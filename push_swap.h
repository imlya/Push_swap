/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:41 by imatek            #+#    #+#             */
/*   Updated: 2024/07/09 17:37:59 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				valeur;
	int				position;
	int				cost;
	char			*temp;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

// commandes
void				ft_push(t_list **lst1, t_list **lst2);
void				ft_pa(t_list **a, t_list **b, int flag);
void				ft_pb(t_list **b, t_list **a, int flag);
void				ft_reverse_rotate(t_list **lst);
void				ft_rra(t_list **a, int flag);
void				ft_rrb(t_list **b, int flag);
void				ft_rrr(t_list **a, t_list **b, int flag);
void				ft_rotate(t_list **lst);
void				ft_ra(t_list **a, int flag);
void				ft_rb(t_list **b, int flag);
void				ft_rr(t_list **a, t_list **b, int flag);
void				ft_swap(t_list **lst);
void				ft_sa(t_list **a, int flag);
void				ft_sb(t_list **b, int flag);
void				ft_ss(t_list **a, t_list **b, int flag);
// lists
t_list				*ft_lstnew(char *temp);
t_list				*ft_lst_prev_last(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
//parse
int					ft_check_double(t_list **a);
int					ft_check_digits(t_list **a);
int					ft_check_limits(t_list **a);
void				ft_init_stacka(char **av, t_list **a);
int					ft_parse(char **av, t_list **a);
void				ft_free_tab(char **tab);
void				ft_print(t_list *a);

#endif