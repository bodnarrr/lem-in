/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:08:27 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_lem_int(char *str)
{
	if (ft_atoi(str) > 0 && ft_atoi(str) <= INT_MAX)
		return (1);
	return (0);
}

static int	ft_check_anterr_type(char **str, t_lemin *prm)
{
	int		line_type;

	line_type = ft_check_line_type(*str);
	if (line_type == ERRO)
	{
		ft_strdel(str);
		prm->err_no = 0;
	}
	else if ((line_type != ANTS && line_type != CMNT) || ft_strlen(*str) == 0)
	{
		ft_strdel(str);
		prm->err_no = 1;
	}
	else if (ft_str_allnum(*str))
	{
		if (ft_atoi(*str) < 0)
			prm->err_no = 2;
		else if (ft_atoi(*str) == 0)
			prm->err_no = 3;
		else if (ft_atoi(*str) > INT_MAX)
			prm->err_no = 4;
		ft_strdel(str);
	}
	return (1);
}

int			ft_get_ants_number(t_lemin *prm, t_parse *p)
{
	int		line_type;

	if (get_next_line(0, &(p->cur_lin)) == 1)
	{
		line_type = ft_check_line_type(p->cur_lin);
		if (line_type == ANTS && ft_lem_int(p->cur_lin))
		{
			prm->ants = ft_atoi(p->cur_lin);
			prm->input = ft_join_lem(&(prm->input), &(p->cur_lin));
			ft_strdel(&(p->cur_lin));
			(prm->line)++;
			return (prm->ants);
		}
		else if (line_type == CMNT && (prm->input =
			ft_join_lem(&(prm->input), &(p->cur_lin))))
		{
			ft_strdel(&(p->cur_lin));
			(prm->line)++;
			return (ft_get_ants_number(prm, p));
		}
		else if (ft_check_anterr_type(&(p->cur_lin), prm) >= 0)
			return (-1);
	}
	prm->err_no = 5;
	return (-1);
}
