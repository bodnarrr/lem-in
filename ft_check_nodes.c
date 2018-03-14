/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:44:38 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/13 20:44:39 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_nodes(t_nodes **all, t_antparse *p, t_lemin *prm)
{
	if (p->start != 1 && p->finish == 1)
	{
		prm->err_no = 13;
		ft_clear_nodes(all);
		ft_strdel(&(prm->input));
		return (-1);
	}
	else if (p->start == 1 && p->finish != 1)
	{
		prm->err_no = 14;
		ft_clear_nodes(all);
		ft_strdel(&(prm->input));
		return (-1);
	}
	else if (p->start != 1 && p->finish != 1)
	{
		prm->err_no = 15;
		ft_clear_nodes(all);
		ft_strdel(&(prm->input));
		return (-1);
	}
	return (1);
}
