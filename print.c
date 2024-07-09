/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:46 by imatek            #+#    #+#             */
/*   Updated: 2024/07/09 17:39:09 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_print(t_list *a)
{
    t_list  *temp_a;
    int     i;

    temp_a = a;
    i = 0;
    while (temp_a)
    {
      printf("NOEUD %d\n", i);
      printf("valeur %d\n", temp_a->valeur);
      printf("position %d\n", temp_a->position);
      printf("cost %d\n", temp_a->cost);
      printf("temp %s\n", temp_a->temp);
      i++;
      temp_a = temp_a->next;
    }
}
