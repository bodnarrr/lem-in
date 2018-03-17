/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:44:50 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_clear_queue(t_queue *q)
{
	t_queue		*fordel;

	fordel = NULL;
	while (q)
	{
		fordel = q;
		q = q->next;
		free(fordel);
	}
}

static t_queue	*ft_queue_add(t_queue *all, t_nodes *add, int dist,
	t_nodes *from)
{
	t_queue		*head;
	t_queue		*new;

	head = all;
	new = (t_queue*)malloc(sizeof(t_queue));
	new->node = add;
	add->came_from = from;
	add->dist = dist;
	new->next = NULL;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		all = new;
	return (all);
}

void			ft_traverse(t_nodes **all, t_queue *q)
{
	t_queue		*qh;
	t_nodes		*head;
	t_conns		*links;

	head = *all;
	while (head->start != 1)
		head = head->next;
	q = ft_queue_add(q, head, 0, NULL);
	qh = q;
	while (qh)
	{
		if (qh->node->fin == 1)
			break ;
		links = qh->node->conn;
		while (links)
		{
			if (links->node->visit == 0)
				q = ft_queue_add(q, links->node, qh->node->dist + 1, qh->node);
			links = links->next;
		}
		qh->node->visit = 1;
		qh = qh->next;
	}
	ft_clear_queue(q);
}
