/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_road.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:54:56 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 17:28:05 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodes		*ft_check_if_road(t_nodes **all, t_lemin *prm)
{
	t_nodes	*head;

	head = *all;
	while (head->fin != 1)
		head = head->next;
	if (head->came_from == NULL)
	{
		prm->err_no = 19;
		return (ft_clear_nodes(all));
	}
	else
		return (*all);
}
