/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:38:41 by imatek            #+#    #+#             */
/*   Updated: 2024/07/24 21:14:28 by imatek           ###   ########.fr       */
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
	int				value;
	int				position;
	int				cost;
	int				group;
	int				index;
	char			*temp;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

// 				COMMANDES
void				ft_push(t_list **lst1, t_list **lst2);
void				ft_pa(t_list **a, t_list **b, int flag);
void				ft_pb(t_list **b, t_list **a, int flag);
void				ft_swap(t_list **lst);
void				ft_sa(t_list **a, int flag);
void				ft_sb(t_list **b, int flag);
void				ft_ss(t_list **a, t_list **b, int flag);
void				ft_rotate(t_list **lst);
void				ft_ra(t_list **a, int flag);
void				ft_rb(t_list **b, int flag);
void				ft_rr(t_list **a, t_list **b, int flag);
void				ft_reverse_rotate(t_list **lst);
void				ft_rra(t_list **a, int flag);
void				ft_rrb(t_list **b, int flag);
void				ft_rrr(t_list **a, t_list **b, int flag);
//          	LISTES
t_list				*ft_lstnew(char *temp);
void				ft_lstclear(t_list **lst);
t_list				*ft_lst_prev_last(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_free_tab(char **tab);
//               PARSING
int					ft_check_double(t_list **a);
int					ft_check_digits(t_list **a);
int					ft_check_limits(t_list **a);
void				ft_init_stacka(char **av, t_list **a);
int					ft_parse(char **av, t_list **a);
//               SORTING
int					ft_already_sorted(t_list **a);
int					ft_sort3(t_list **a);
void				ft_set_top(char list, t_list **lst, t_list *cheapest);
t_list				*ft_smallest(t_list **lst);
t_list				*ft_biggest(t_list **lst);
int					ft_is_smallest(t_list *smallest, t_list **lst);
int					ft_is_biggest(t_list *biggest, t_list **lst);
void				ft_optimization(t_list **a, t_list **b, t_list *cheapest);
void				ft_optimization_reverse(t_list **b, t_list **a,
						t_list *cheapest);
void				ft_sort_index(t_list **lst);
// void				ft_optimized_push(t_list *node, t_list **a, t_list **b);
//				UTILS
void				ft_set_groups(t_list **lst);
void				ft_push_groups(t_list **a, t_list **b);
void				ft_cost(t_list **lst);
t_list				*ft_cheapest(t_list **lst);
void				ft_set_position(t_list **lst);
int					ft_position(t_list **lst, t_list *node);
void				ft_target(t_list **a, t_list **b);
void				ft_target_reverse(t_list **a, t_list **b);
void				ft_reset_target(t_list **lst);
void				ft_push_swap(t_list **stack_a, t_list **stack_b);
void				ft_print(t_list *a);

#endif
