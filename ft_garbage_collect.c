/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:36:21 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/09 20:36:23 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_garbage_collect(t_nodes *all, t_queue *q)
{
	t_nodes	*delnode;
	t_queue	*delq;

	while (all)
	{
		delnode = all;
		all = all->next;
		ft_strdel(&(delnode->name));
		free(delnode);
	}
	while (q)
	{
		delq = q;
		q = q->next;
		free(delq);
	}
}
