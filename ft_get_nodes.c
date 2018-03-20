/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:16:40 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_room_check(t_nodes *head, char *str, t_lemin *prm)
{
	char		**args;
	int			res;

	args = ft_strsplit(str, ' ');
	res = 1;
	while (head && res == 1)
	{
		if (ft_strequ(args[0], head->name) && (prm->err_no = 9) == 9)
			res = 0;
		if (ft_atoi(args[1]) == head->x && ft_atoi(args[2]) == head->y)
		{
			prm->err_no = 10;
			res = 0;
		}
		head = head->next;
	}
	if (ft_strchr(args[0], '-'))
	{
		prm->err_no = 12;
		res = 0;
	}
	ft_clear_lines(args, 3);
	return (res);
}

static	void	ft_nodes_noret(t_parse *p, t_lemin *prm, int line_type)
{
	if (line_type == STRT && p->start == -1)
		ft_node_strt_ok(p, prm);
	else if (line_type == FNSH && p->finish == -1)
		ft_node_fnsh_ok(p, prm);
	else if (line_type == CMNT)
		ft_node_cmnt(prm, p);
}

static t_nodes	*ft_nodes_ret(t_nodes *head, t_lemin *prm, t_parse *p,
					int line_type)
{
	if (line_type == STRT && p->start != -1)
		return (ft_node_strt_err(p, prm, head));
	else if (line_type == FNSH && p->finish != -1)
		return (ft_node_fnsh_err(p, prm, head));
	else if (line_type == ERRO || line_type == ANTS)
		return (ft_node_erroants(head, prm, p));
	else if (line_type == CONN)
		return (ft_node_conn(prm, head, p));
	else if (ft_strlen(p->cur_lin) == 0)
		return (ft_node_empty(p, head));
	return (head);
}

t_nodes			*ft_get_nodes(t_lemin *prm, t_parse *p)
{
	t_nodes		*head;
	int			line_type;

	head = NULL;
	line_type = 0;
	while (1)
	{
		if (get_next_line(0, &(p->cur_lin)))
		{
			line_type = ft_check_line_type(p->cur_lin);
			if ((line_type == STRT && p->start != -1) || (line_type == FNSH
				&& p->finish != -1) || (line_type == ERRO || line_type == ANTS)
				|| (line_type == CONN) || ft_strlen(p->cur_lin) == 0)
				return (ft_nodes_ret(head, prm, p, line_type));
			else if (line_type == ROOM
				&& (head = ft_node_node(head, p, prm)) == NULL)
				return (head);
			else if ((line_type == STRT && p->start == -1) || line_type == CMNT
				|| (line_type == FNSH && p->finish == -1))
				ft_nodes_noret(p, prm, line_type);
		}
		else
			return (head);
	}
	return (head);
}
