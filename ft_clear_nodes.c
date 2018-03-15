/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:39:04 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/13 20:39:06 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_clear_conns(t_nodes *curr_node)
{
	t_conns		*fordel;

	if (!curr_node)
		return ;
	while (curr_node->conn)
	{
		fordel = curr_node->conn;
		curr_node->conn = curr_node->conn->next;
		free(fordel);
	}
}

t_nodes			*ft_clear_nodes(t_nodes **all)
{
	t_nodes		*fordel;

	while (*all)
	{
		fordel = *all;
		ft_strdel(&((*all)->name));
		*all = (*all)->next;
		if (fordel->conn)
			ft_clear_conns(fordel);
		free(fordel);
	}
	return (NULL);
}
