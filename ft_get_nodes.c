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

/*
**		On this stage there aren't allocated connections with other nodes
*/

static void		ft_clear_nodes(t_nodes **all)
{
	t_nodes		*fordel;
	if (!all || *all)
		return ;
	while (*all)
	{
		fordel = *all;
		ft_strdel((*all)->name);
		all = all->next;
		free(fordel);
	}
	*all = NULL;
}

t_nodes			*ft_get_nodes(t_lemin *prm, t_antparse *p)
{
	t_nodes		*head;
	int			gnl;

	head = NULL;
	while ()
	{
		if (get_next_line(0, &(p->cur_lin)))
		{
			if (ft_check_line_type(p->cur_lin) == ROOM)
			{
				head = ft_add_room(head, p, ft_strsplit(p->cur_lin, ' '));
				prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
			}

			if (ft_check_line_type(p->cur_lin) == STRT)
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
				}
			}
			if (ft_check_line_type(p->cur_lin) == FNSH)
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
			if (ft_check_line_type(p->cur_lin) == CMNT)
			{
				prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				t_strdel(&(p->cur_lin))
			}
			if (ft_check_line_type(p->cur_lin) == ERRO
				|| ft_check_line_type(p->cur_lin) == ANTS)
			{
				ft_check_roomerr_type(p->cur_lin);
				ft_clear_nodes(&head);
				return (head);
			}
			if (ft_check_line_type(p->cur_lin) == CONN)
			{
				ft_strdel(&(p->cur_lin));
				return (head);
			}
		}
		else
		{
			check errors;
			break ;
		}

	}

	return (head);
}
	

	check if node is NULL before free 