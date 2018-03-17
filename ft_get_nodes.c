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

static int		ft_room_check(t_nodes *head, char *str, t_lemin *prm)
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

/*
**		On this stage there aren't allocated connections with other nodes
*/

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
			if (ft_strlen(p->cur_lin) == 0)
			{
				ft_strdel(&(p->cur_lin));
				return (ft_clear_nodes(&head));
			}
			else if (line_type == ROOM)
			{
				if (ft_room_check(head, p->cur_lin, prm) == 1)
				{
					ft_add_room(&head, p, ft_strsplit(p->cur_lin, ' '));
					(prm->line)++;
					prm->input = ft_join_lem(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_strdel(&(p->cur_lin));
					return (ft_clear_nodes(&head));
				}
			}
			else if (line_type == STRT)
			{
				if (p->start == -1)
				{
					p->start = 0;
					(prm->line)++;
					prm->input = ft_join_lem(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_strdel(&(p->cur_lin));
					prm->err_no = 6;
					return (ft_clear_nodes(&head));
				}
			}
			else if (line_type == FNSH)
			{
				if (p->finish == -1)
				{
					p->finish = 0;
					(prm->line)++;
					prm->input = ft_join_lem(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_strdel(&(p->cur_lin));
					prm->err_no = 7;
					return (ft_clear_nodes(&head));
				}
			}
			else if (line_type == CMNT)
			{
				(prm->line)++;
				prm->input = ft_join_lem(&(prm->input), &(p->cur_lin));
			}
			else if (line_type == ERRO || line_type == ANTS)
			{
				prm->err_no = 11;
				ft_strdel(&(p->cur_lin));
				return (ft_clear_nodes(&head));
			}
			else if (line_type == CONN)
			{
				(prm->line)++;
				return (head);
			}
		}
		else
			return (head);
	}
	return (head);
}
