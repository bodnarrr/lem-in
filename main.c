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

int			main(void)
{
	t_road	*road;
	t_nodes	*nodes;
	t_lemin	prm;

	nodes = ft_get_nodes(&prm); //make all rooms for lem-in algo
	// connect correct connections;
	ft_traverse(nodes);
	road = ft_get_min_trace(nodes); //get road
	ft_print_result(prm, road);
	ft_garbage_coolector();
}
