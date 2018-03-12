/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:12:33 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/09 20:12:34 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void static		ft_initialize_parcing(t_lemparse *parse, t_lemin *prm)
{
	ft_bzero(parse, sizeof(t_lemparse));
	parse->err_no = -1;
	ft_bzero(prm, sizeof(t_lemin));
	prm->input = ft_strnew(0);
}

int			main(void)
{
	t_road		*road;
	t_nodes		*nodes;
	t_lemin		prm;
	t_lemparse	parse;

	ft_initialize(&parse, &prm);
	if (ft_get_ants_number(&prm, &parse) == -1)
		ft_print_err(prm.err_no);
	nodes = ft_get_nodes(&prm); //make all rooms for lem-in algo
	// connect correct connections;
	ft_traverse(nodes);
	road = ft_get_min_trace(nodes); //get road
	ft_print_result(prm, road);
	ft_garbage_collector();
}
