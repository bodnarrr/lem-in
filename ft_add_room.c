/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:42:35 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_add_room(t_nodes **head, t_parse *p, char **room)
{
	t_nodes	*new;
	t_nodes	*all;

	new = (t_nodes*)malloc(sizeof(t_nodes));
	ft_bzero(new, sizeof(t_nodes));
	new->name = ft_strdup(room[0]);
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	if (p->start == 0 && (new->start = 1))
		p->start = 1;
	if (p->finish == 0 && (new->fin = 1))
		p->finish = 1;
	all = *head;
	if (head && *head)
	{
		while (all->next)
			all = all->next;
		all->next = new;
	}
	else
		*head = new;
	ft_clear_lines(room, 3);
}
