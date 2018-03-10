/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:57:37 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/10 20:57:38 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_road		*ft_get_min_trace(t_nodes *all)
{
	t_nodes	*head;
	t_road	*road;
	int		i;

	head = all;
	while (all->fin != 1)
		all = all->next;
	road = (t_road*)malloc(sizeof(t_road * (all->dest + 1));
	i = 0;
	while (all != NULL)
	{
		(road[i++])->name = ft_strdup(all->name);
		all = all->came_from;
	}
	return (road);
}
