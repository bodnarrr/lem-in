/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:12:33 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 14:43:23 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_args(char **av, t_lemin *prm)
{
	while (*av)
	{
		if (ft_strequ(*av, "-r"))
			prm->proad = 1;
		if (ft_strequ(*av, "-m"))
			prm->m = 1;
		if (ft_strequ(*av, "-c"))
			prm->c = 1;
		av++;
	}
}

void	ft_initialize_parsing(t_parse *parse, t_lemin *prm, int ac, char **av)
{
	if (ac == 0)
		return ;
	ft_bzero(parse, sizeof(t_parse));
	ft_bzero(prm, sizeof(t_lemin));
	parse->start = -1;
	parse->finish = -1;
	prm->line = 0;
	prm->input = ft_strnew(0);
	prm->err_no = -1;
	ft_parse_args(av, prm);
}

int		main(int ac, char **av)
{
	t_nodes		*nodes;
	t_lemin		prm;
	t_parse		parse;

	ft_initialize_parsing(&parse, &prm, ac, av);
	if (ft_get_ants_number(&prm, &parse) == -1 && ft_print_ant_err(&prm))
		return (1);
	if ((nodes = ft_get_nodes(&prm, &parse)) == NULL && ft_print_ant_err(&prm))
		return (1);
	if (ft_check_nodes(&nodes, &parse, &prm) == NULL && ft_print_ant_err(&prm))
		return (1);
	if (ft_get_connects(&nodes, &parse, &prm) == NULL && ft_print_ant_err(&prm))
		return (1);
	ft_traverse(&nodes, NULL);
	if (ft_check_if_road(&nodes, &prm) == NULL && ft_print_ant_err(&prm))
		return (1);
	ft_print_result(nodes, prm);
	ft_clear_nodes(&nodes);
	ft_strdel(&(prm.input));
	return (0);
}
