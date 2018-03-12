/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:08:27 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/12 14:08:29 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_print_ant_err(t_lemin *prm)
{
	ft_strdel(&(prm->input));
	ft_printf("%s\n", g_errors[prm->err_no]);
	return (1);
}

static int	ft_check_anterr_type(char *str, t_lemin *prm)
{
	if (ft_check_line_type(str) == ERRO)
		prm->err_no = 0;
	else if (ft_check_line_type(str) != ANTS && ft_check_line_type(str) != CMNT)
		prm->err_no = 1;
	else if (ft_str_allnum(str))
	{
		if (ft_atoi(str) < 0)
			prm->err_no = 2;
		else if (ft_atoi(str) == 0)
			prm->err_no = 3;
		else if (ft_atoi(str) > MAX_INT)
			prm->err = 4;
	}
	return (1);
}

int			ft_get_ants_number(t_lemin *prm, t_lemparse *p)
{
	if (get_next_line(0, &(p->cur_lin)) == 1)
	{
		if (ft_check_line_type(p->cur_lin) == ANTS && ft_atoi(p->cur_lin) > 0
		ft_atoi(p->cur_lin) <= MAX_INT)
		{
			prm->lems = ft_atoi(p->cur_lin);
			p->stage = 1;
			prm->input = ft_str_clear_join(&(prm->input), &(p->cur_lin));
			ft_strdel(&(p->cur_lin));
			return (prm->lems);
		}
		else if (ft_check_line_type(parse.cur_lin) == CMNT && (prm->input =
			ft_str_clear_join(&(prm->input), &(parse.cur_lin))))
		{
			ft_strdel(&(parse->cur_lin));
			return (ft_get_ants_number(prm, p));
		}
		else if (ft_check_anterr_type(p->cur_lin, prm) >= 0)
			return (-1);
	}
	prm->err_no = 5;
	return (-1);
}
