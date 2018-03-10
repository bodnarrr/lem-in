/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:44:50 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/09 20:44:51 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_clear_queue(t_queque *q)
{
	t_queque	*fordel;

	fordel = NULL;
	while (q)
	{
		fordel = q;
		q = q->next;
		free(fordel);
	}
}

void			ft_traverse(t_nodes *all)
{
	t_queque	*q;
	t_queque	*q_head;
	t_nodes		*head;
	t_nodes		*curr;
	
	head = all;
	while (all->start != 1)
		all = all->next;
	q = ft_queue_add(q, all, 0, NULL);
	q_head = q;
	curr = NULL;
	while (q)
	{
		while (q->room->conn) //while there rooms connected with current
			if (q->room->conn->visit == 0)
				q = ft_queue_add(q, q->room->conn, q->room->dist + 1, q->room);
		q->room->came_from = curr; //save pointer to room where we have come
		curr = q->room; //save current room
		q->room->visit = 1;
		if (q->room->fin == 1)
			break ;
		q = q->next;
	}
	ft_clear_queue(q_head);
}
