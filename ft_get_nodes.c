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

static int		ft_check_if_room(char **lines)
{
	int			res;
	char		**fordel;

	res = 0;
	if (ft_str_allnum((*lines)[1]) && ft_str_allnum((*lines)[2]))
		res = 1;
	fordel = lines;
	while (*lines)
	{
		ft_strdel(*lines);
		lines++;
	}
	free(fordel);
	return (res);
}

/*
**      ANTS - <int>
**		ROOM - <name> <int> <int>
**		CONN - <name1>-<name2>
*/



t_nodes			*ft_get_nodes(t_lemin *prm)
{
	t_nodes		*all;
	t_nodes		*head;
	t_lemparse 	parse;
	char		rt;

	ft_initialize_parcing(&parse);

	//get number of ants
	if (rt = get_next_line(0, &(parse.cur_lin)) == 1)
	{
		if (ft_check_line_type(parse.cur_lin) == 1 && ft_atoi(parse.cur_lin) > 0
		ft_atoi(parse.cur_lin) <= MAX_INT)
		{
			prm->lems = ft_atoi(parse->cur_lin);
			parse->stage = 1;
			prm->input = ft_str_clear_join(&(prm->input), &(parse.cur_lin));
			ft_strdel(&(parse->cur_lin));
		}
		else if (ft_check_line_type(parse.cur_lin) == CMNT)
		{
			prm->input = ft_str_clear_join(&(prm->input), &(parse.cur_lin));
			ft_strdel(&(parse->cur_lin));
		}
		else
		{
			ft_check_anterr_type(parse->cur_lin, prm);
			return (NULL);
		}
	}


	while (parse->err_no < 0)
	{
		get_next_line(0, &(parse->cur_lin));
		ft_take_inf_from_line(&parse, ft_check_line_type(&parse));
	}
}
	