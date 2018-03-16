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

static t_queue	*ft_queue_add(t_queue *all, t_nodes *add, int dist, t_nodes *from)
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

void			ft_traverse(t_nodes **all)
{
	t_queue		*q;
	t_queue		*q_h;
	t_nodes		*head;
	t_conns		*links;

	q = NULL;
	head = *all;
	while (head->start != 1)
		head = head->next;
	q = ft_queue_add(q, head, 0, NULL);
	q_h = q;
	while (q_h)
	{
		if (q_h->node->fin == 1)
			break ;
		links = q_h->node->conn;
		while (links)
		{
			if (links->node->visit == 0)
				q = ft_queue_add(q, links->node, q_h->node->dist + 1, q_h->node);
			links = links->next;
		}
		q_h->node->visit = 1;
		q_h = q_h->next;
	}
	ft_clear_queue(q);
}
