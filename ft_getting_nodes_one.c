/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getting_nodes_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:56:02 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 16:56:02 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_node_cmnt(t_lemin *prm, t_parse *p)
{
	(prm->line)++;
	prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
}

t_nodes		*ft_node_empty(t_parse *p, t_nodes *head)
{
	ft_strdel(&(p->cur_lin));
	return (ft_clear_nodes(&head));
}

t_nodes		*ft_node_node(t_nodes *head, t_parse *p, t_lemin *prm)
{
	if (ft_room_check(head, p->cur_lin, prm) == 1)
	{
		ft_add_room(&head, p, ft_strsplit(p->cur_lin, ' '));
		(prm->line)++;
		prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
	}
	else
	{
		ft_strdel(&(p->cur_lin));
		return (ft_clear_nodes(&head));
	}
	return (head);
}

t_nodes		*ft_node_erroants(t_nodes *head, t_lemin *prm, t_parse *p)
{
	prm->err_no = 11;
	ft_strdel(&(p->cur_lin));
	return (ft_clear_nodes(&head));
}

void		ft_node_strt_ok(t_parse *p, t_lemin *prm)
{
	p->start = 0;
	(prm->line)++;
	prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
}
