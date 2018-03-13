/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:39:04 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/13 20:39:06 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_clear_nodes(t_nodes **all)
{
	t_nodes		*fordel;

	if (!all || !*all)
		return ;
	while (*all)
	{
		fordel = *all;
		ft_strdel(&((*all)->name));
		*all = (*all)->next;
		free(fordel);
	}
}
