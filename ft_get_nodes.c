/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:16:40 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/11 12:16:41 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_room_check(t_nodes *head, t_antparse *p, t_lemin *prm)
{
	char		**args;
	int			res;

	args = ft_strsplit(p->cur_lin, ' ');
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
	ft_clear_arg_room(args);
	return (res);
}

/*
**		On this stage there aren't allocated connections with other nodes
*/

t_nodes			*ft_get_nodes(t_lemin *prm, t_antparse *p)
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
				return (head);
			else if (line_type == ROOM)
			{
				if (ft_room_check(head, p, prm) == 1)
				{
					ft_add_room(&head, p, ft_strsplit(p->cur_lin, ' '));
					prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_clear_nodes(&head);
					return (head);
				}
			}
			else if (line_type == STRT)
			{
				if (p->start == -1)
				{
					p->start = 0;
					prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_clear_nodes(&head);
					ft_strdel(&(p->cur_lin));
					prm->err_no = 6;
					return (head);
				}
			}
			else if (line_type == FNSH)
			{
				if (p->finish == -1)
				{
					p->finish = 0;
					prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_clear_nodes(&head);
					ft_strdel(&(p->cur_lin));
					prm->err_no = 7;
					return (head);
				}
			}
			else if (line_type == CMNT)
			{
				prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				ft_strdel(&(p->cur_lin));
			}
			else if (line_type == ERRO || line_type == ANTS)
			{
				prm->err_no = 11;
				ft_clear_nodes(&head);
				return (head);
			}
			else if (line_type == CONN)
			{
				ft_strdel(&(p->cur_lin));
				return (head);
			}
		}
		else
			return (head);
	}
	return (head);
}


	//check if node is NULL before free