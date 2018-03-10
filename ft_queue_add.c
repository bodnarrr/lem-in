/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:29:20 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/09 20:29:21 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*ft_queue_add(t_queue *work, t_nodes *add, int dist, t_nodes *from)
{
	t_queue	*head;
	t_queue	*new;

	head = work;
	new = (t_queue*)malloc(sizeof(t_queue));
	add->came_from = from;
	new->node = add;
	add->dist = dist;
	new->next = NULL;
	if (work)
	{
		while (work->next)
			work = work->next;
		work->next = new;
	}
	else
		work = new;
	return (head);
}
