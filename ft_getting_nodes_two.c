/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getting_nodes_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:59:43 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 16:59:44 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodes		*ft_node_strt_err(t_parse *p, t_lemin *prm, t_nodes *head)
{
	ft_strdel(&(p->cur_lin));
	prm->err_no = 6;
	return (ft_clear_nodes(&head));
}

void		ft_node_fnsh_ok(t_parse *p, t_lemin *prm)
{
	p->finish = 0;
	(prm->line)++;
	prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
}

t_nodes		*ft_node_fnsh_err(t_parse *p, t_lemin *prm, t_nodes *head)
{
	ft_strdel(&(p->cur_lin));
	prm->err_no = 7;
	return (ft_clear_nodes(&head));
}

t_nodes		*ft_node_conn(t_lemin *prm, t_nodes *head)
{
	(prm->line)++;
	return (head);
}
