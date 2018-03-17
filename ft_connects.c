/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:29:11 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 20:29:11 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodes		*ft_conn_erro(t_nodes **all, t_parse *p, t_lemin *prm)
{
	prm->err_no = 17;
	ft_strdel(&(p->cur_lin));
	return (ft_clear_nodes(all));
}

t_nodes		*ft_conn_cmnt(t_nodes **all, t_parse *p, t_lemin *prm)
{
	(prm->line)++;
	prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
	return (*all);
}

t_nodes		*ft_conn_room(t_nodes **all, t_parse *p, t_lemin *prm)
{
	prm->err_no = 16;
	ft_strdel(&(p->cur_lin));
	return (ft_clear_nodes(all));
}

t_nodes		*ft_conn_conn(t_nodes **all, t_parse *p, t_lemin *prm)
{
	if (ft_conn_check(*all, p->cur_lin, prm) == 1)
	{
		ft_add_conn(all, ft_strsplit(p->cur_lin, '-'));
		(prm->line)++;
		prm->input = ft_join_lem(&(prm->input), &(p->cur_lin), prm);
	}
	else
	{
		ft_strdel(&(p->cur_lin));
		return (ft_clear_nodes(all));
	}
	return (*all);
}
