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
	parse->start = -1;
	parse->finish = -1;
	parse->cur_lin = ft_strnew(0);
	prm->line = 0;
	prm->input = ft_strnew(0);
	prm->err_no = -1;
}

int			main(void)
{
	// t_road		*road;
    t_nodes		*nodes;
    t_nodes     *test_copy;
	t_lemin		prm;
	t_antparse	parse;

	ft_initialize_parsing(&parse, &prm);
	if (ft_get_ants_number(&prm, &parse) == -1 && ft_print_ant_err(&prm))
		return (1);
	ft_printf("ants = %d\n", prm.ants);

	if ((nodes = ft_get_nodes(&prm, &parse)) == NULL && ft_print_ant_err(&prm)) //make all rooms for lem-in algo
	    return (1);
	if (ft_check_nodes(&nodes, &parse, &prm) == NULL && ft_print_ant_err(&prm))
		return (1);
	if (ft_get_connects(&nodes, &parse, &prm) == NULL && ft_print_ant_err(&prm))
	    return (1);
    test_copy = nodes;
    while (test_copy)
    {
        ft_printf("Name: %s\nX = %d\nY = %d\n", test_copy->name, test_copy->x, test_copy->y);
        if (test_copy->conn)
        {
            while(test_copy->conn)
            {
                ft_printf("conn = %s\n", test_copy->conn->node->name);
                test_copy->conn = test_copy->conn->next;
            }
            ft_printf("\n");
        }
        test_copy = test_copy->next;
    }
	ft_printf("Looks like all OK\n");
	ft_clear_nodes(&nodes);

	
	// 	ft_print_nodes_err(&prm);
	// // connect correct connections;
	// ft_traverse(nodes);
	// road = ft_get_min_trace(nodes); //get road
	// ft_print_result(prm, road);
	// ft_garbage_collector();
}
