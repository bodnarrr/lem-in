/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_conn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:03:22 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/10 14:03:24 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_new_conn(t_nodes *all, char *add_to, t_nodes *conn)
{
	t_nodes	*new;

	while (all != NULL && ft_strequ(all->name, add_to) != 1)
		all = all->next;
	new = (t_nodes*)malloc(sizeof(t_nodes));
	new = ft_memcpy(new, conn, sizeof(t_nodes));
	while (all->conn->next)
		all->conn = all->conn->next;
	all->conn->next = new;
}
