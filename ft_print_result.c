/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:05:09 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/16 20:39:10 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_result(t_nodes *nodes, t_lemin prm)
{
	t_nodes	*end;

	while (nodes)
    {
        if (nodes->fin == 1)
            end = nodes;
        if (nodes->start == 1)
            nodes->ant_n = 1;
        nodes = nodes->next;
    }
    while (end->ant_n < prm.ants)
    {
        nodes = end;
        while (nodes->start != 1)
        {
            if (nodes->came_from->ant_n > prm.ants)
                (nodes->ant_n)++;
            if (nodes->came_from->ant_n <= prm.ants && nodes->came_from->ant_n > 0)
            {
                ft_printf("L%d-%s ", nodes->came_from->ant_n, nodes->name);
                (nodes->ant_n)++;
                if (nodes->came_from->start == 1)
                    (nodes->came_from->ant_n)++;
            }
            nodes = nodes->came_from;
        }
        ft_printf("\n");
    }
}
