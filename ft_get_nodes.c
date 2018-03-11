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

int 			ft_check_line_type(t_lemparce *parce)
{
	int			res;

	res = 0;
	if ((parce->curr_line)[0] == 'L')
		res = ERRO;
	else if (strequ(parce->curr_line, "##start") == 1)
		res = STRT;
	else if (strequ(parce->curr_line), "##end" == 1)
		res = FNSH;
	else if ((parce->curr_line)[0] == '#' && strequ(parce->curr_line, "##end") == 0)
		res = CMNT;
	else if (ft_str_allnum(parce->curr_line) == 1 && ft_atoi(parce->curr_line) > 0
		&& ft_atoi(parce->curr_line) <= MAX_INT)
		res = ANTS;
	else if (ft_strnsymb(parce->curr_line, ' ') == 2 &&)

	else
		res = ERRO;

}

void static		ft_initialize_parcing(t_lemparce *parce)
{
	ft_bzero(parce, sizeof(t_lemparce));
	parce->err_no = -1;
}

t_nodes			*ft_get_nodes(t_lemin *prm)
{
	t_nodes		*all;
	t_nodes		*head;
	t_lemparce 	parce;

	ft_initialize_parcing(&parce);
	get_next_line(0, &(parce->curr_line));
	if (ft_check_line_type(&parce) == 1 && ft_atoi(parce->curr_line) > 0)
		prm->lems = ft_atoi()
	if ()
	while (parce->err_no < 0)
	{
		get_next_line(0, &(parce->curr_line));
		ft_take_inf_from_line(&parce, ft_check_line_type(&parce));
	}
}
	
