/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_connects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:29:04 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/14 14:29:04 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_add_new_conn(t_nodes *add, t_nodes *add_to)
{
	t_conns		*new;
	t_conns		*cpy;

    if (add == add_to)
        return ;
	if ((cpy = add_to->conn))
	{
		while (cpy->next)
		{
			if (cpy->node == add)
				return ;
			cpy = cpy->next;
		}
		new = (t_conns*)malloc(sizeof(t_conns));
		new->node = add;
		new->next = NULL;
		cpy->next = new;
	}
	else
	{
		new = (t_conns*)malloc(sizeof(t_conns));
        new->node = add;
        new->next = NULL;
        add_to->conn = new;
	}
}

static void		ft_add_conn(t_nodes **all, char **names)
{
	t_nodes	*name_one;
	t_nodes	*name_two;
	t_nodes	*head;

	name_one = NULL;
	name_two = NULL;
	head = *all;
	while (head)
	{
		if (ft_strequ(head->name, names[0]))
			name_one = head;
		if (ft_strequ(head->name, names[1]))
			name_two = head;
		if (name_one && name_two)
			break ;
		head = head->next;
	}
	ft_add_new_conn(name_one, name_two);
	ft_add_new_conn(name_two, name_one);
	ft_clear_lines(names, 2);
}

static int	ft_conn_check(t_nodes *all, char *str, t_lemin *prm)
{
	int		res;
	char	**room_names;
	int		i;

	res = 7;
	room_names = ft_strsplit(str, '-');
	while (all)
	{
		if (ft_strequ(all->name, room_names[0]))
			res = res & 11;
		if (ft_strequ(all->name, room_names[1]))
			res = res & 13;
		all = all->next;
	}
	if (res != 1)
		prm->err_no = 18;
	i = 0;
	while (room_names[i])
	{
		ft_strdel(&(room_names[i]));
		i++;
	}
	free(room_names);
	return (res);
}

t_nodes		*ft_get_connects(t_nodes **all, t_antparse *p, t_lemin *prm)
{
	int		line_type;

	if (p->cur_lin)
	{
		if (ft_conn_check(*all, p->cur_lin, prm) == 1)
		{
			ft_add_conn(all, ft_strsplit(p->cur_lin, '-'));
			(prm->line)++;
			prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
		}
		else
		{
			ft_strdel(&(p->cur_lin));
			return (ft_clear_nodes(all));
		}
	}
	while (1)
	{
		if (get_next_line(0, &(p->cur_lin)))
		{
			line_type = ft_check_line_type(p->cur_lin);
			if (ft_strlen(p->cur_lin) == 0)
				return (*all);
			else if (line_type == CONN)
			{
				if (ft_conn_check(*all, p->cur_lin, prm) == 1)
				{
					ft_add_conn(all, ft_strsplit(p->cur_lin, '-'));
					(prm->line)++;
					prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
				}
				else
				{
					ft_strdel(&(p->cur_lin));
					return (ft_clear_nodes(all));
				}
			}
			else if (line_type == ROOM)
			{
				prm->err_no = 16;
				ft_strdel(&(p->cur_lin));
				return (ft_clear_nodes(all));
			}
			else if(line_type == CMNT)
			{
				(prm->line)++;
				prm->input = ft_str_clean_join(&(prm->input), &(p->cur_lin));
			}
			else if (line_type == ERRO || line_type == ANTS
				|| line_type == STRT || line_type == FNSH)
			{
				prm->err_no = 17;
				ft_strdel(&(p->cur_lin));
				return (ft_clear_nodes(all));
			}
		}
		else
			return (*all);
	}
	return (*all);
}
