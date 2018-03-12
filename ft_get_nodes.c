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

t_nodes			*ft_get_nodes(t_lemin *prm, t_antparse *p)
{
	t_nodes		*res;
	t_nodes		*head;

	head = (t_nodes*)malloc(sizeof(t_nodes));
	res = head;
	

	p->stage = 2;
	return (res);
}
	