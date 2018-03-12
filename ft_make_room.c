/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:42:35 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/10 14:42:36 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_clear_arg(char **str)
{
	int		i;

	i = -1;
	while (++i < 3)
		ft_strdel(&(str[i]));
	free (str);
}

void		ft_make_room(t_nodes *head, t_antparse *p, char **room) //-1 for start || 1 for finish
{
	t_rooms	*new;
	
	new = (t_nodes*)malloc(sizeof(t_nodes));
	ft_bzero(new, sizeof(t_nodes));
	new->name = ft_strdup(room[0]);
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	if (p->start == 0 && (new->start = 1))
		p->start = 1;
	if (p->finish == 0 && (new->fin = 1))
		p->finish = 1;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		all = head;
	ft_clear_arg(room);
}
