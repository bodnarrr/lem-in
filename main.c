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

void static		ft_initialize_parsing(t_antparse *parse, t_lemin *prm)
{
	ft_bzero(parse, sizeof(t_antparse));
	ft_bzero(prm, sizeof(t_lemin));
	prm->input = ft_strnew(0);
	prm->err_no = -1;
}

int			main(void)
{
	// t_road		*road;
	// t_nodes		*nodes;
	t_lemin		prm;
	t_antparse	parse;

	ft_initialize_parsing(&parse, &prm);
	if (ft_get_ants_number(&prm, &parse) == -1 && ft_print_ant_err(&prm))
		return (1);
	ft_printf("ants = %d\n", prm.ants);
	// nodes = ft_get_nodes(&prm, &parse); //make all rooms for lem-in algo
	// // connect correct connections;
	// ft_traverse(nodes);
	// road = ft_get_min_trace(nodes); //get road
	// ft_print_result(prm, road);
	// ft_garbage_collector();
}
