/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_connects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:44:18 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/10 13:44:19 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_add_connects(char *name1, char *name2, t_nodes *all)
{
	t_nodes	*head;
	
	head = all;
	while (all != NULL && ft_strequ(name1, all->name) != 1)
		all = all->next;
	ft_new_conn(head, name2, all);
	all = head;
	while (all != NULL && ft_strequ(name2, all->name) != 1)
		all = all->next;
	ft_new_conn(head, name1, all); 
}
