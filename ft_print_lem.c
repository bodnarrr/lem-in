/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:05:09 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 17:28:33 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_in_errors.h"

int			ft_print_ant_err(t_lemin *prm)
{
	ft_strdel(&(prm->input));
	if (prm->err_no == -1)
	{
		ft_printf("Line %d: ", prm->line);
		ft_printf("Some crazy ERROR!\n");
		return (1);
	}
	ft_printf("Line %d: ", prm->line);
	ft_printf("%s\n", g_errors[prm->err_no]);
	return (1);
}

static void	ft_print_road(t_nodes *all)
{
	t_nodes	*head;

	head = all;
	while (head->fin != 1)
		head = head->next;
	ft_printf("Road from end to start:\n");
	while (head)
	{
		if (head->start != 1)
			ft_printf("%s--->", head->name);
		else
			ft_printf("%s\n", head->name);
		head = head->came_from;
	}
}

void		ft_print_result(t_nodes *nodes, t_lemin prm)
{
	t_nodes	*end;

	if (prm.proad)
		ft_print_road(nodes);
	ft_printf("%s\n\n", prm.input);
	while (nodes)
	{
		if (nodes->fin == 1)
			end = nodes;
		if (nodes->start == 1)
			nodes->ant_n = 1;
		nodes = nodes->next;
	}
	while (end->ant_n < prm.ants)
	{
		nodes = end;
		while (nodes->start != 1)
		{
			if (nodes->came_from->ant_n > prm.ants)
				(nodes->ant_n)++;
			if (nodes->came_from->ant_n <= prm.ants && nodes->came_from->ant_n > 0)
			{
				ft_printf("L%d-%s ", nodes->came_from->ant_n, nodes->name);
				(nodes->ant_n)++;
				if (nodes->came_from->start == 1)
					(nodes->came_from->ant_n)++;
			}
			nodes = nodes->came_from;
		}
		ft_printf("\n");
	}
}
