/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:44:38 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodes		*ft_check_nodes(t_nodes **all, t_parse *p, t_lemin *prm)
{
	if (p->start != 1 && p->finish == 1)
	{
		prm->err_no = 13;
		ft_strdel(&(prm->input));
		ft_strdel(&(p->cur_lin));
		return (ft_clear_nodes(all));
	}
	else if (p->start == 1 && p->finish != 1)
	{
		prm->err_no = 14;
		ft_strdel(&(prm->input));
		ft_strdel(&(p->cur_lin));
		return (ft_clear_nodes(all));
	}
	else if (p->start != 1 && p->finish != 1)
	{
		prm->err_no = 15;
		ft_strdel(&(prm->input));
		ft_strdel(&(p->cur_lin));
		return (ft_clear_nodes(all));
	}
	return (*all);
}
