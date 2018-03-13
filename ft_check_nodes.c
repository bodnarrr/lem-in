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

int		ft_check_nodes(t_nodes **all, t_lemin *prm)
{
	if (!all)
		prm->err_no = ###;
	else if (prm->start == 1 && prm->finish == 0)
	{
		prm->err_no = ###;	//no finish error
		ft_clear_node(all);
		ft_strdel(&(prm->input));
		return (-1);
	}
	else if (prm->start == 0 && prm->finish == 1)
	{
		prm->err_no = ###;	//no start error
		ft_clear_node(all);
		ft_strdel(&(prm->input));
		return (-1);
	}
	return (1);
}
