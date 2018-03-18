/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:05:09 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 14:43:23 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_print_road(t_nodes *all)
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
	ft_printf("               \\/\n");
	ft_printf("         ___  _@@\n");
	ft_printf("        (___)(_)\n");
	ft_printf("        //|| ||\n");
}

static t_nodes	*ft_find_end(t_nodes *nodes)
{
	t_nodes		*head;
	t_nodes		*end;

	head = nodes;
	while (head)
	{
		if (head->fin == 1)
			end = head;
		if (head->start == 1)
			head->ant_n = 1;
		head = head->next;
	}
	return (end);
}

static int		ft_start_fin(t_lemin prm, t_nodes *end)
{
	int			i;

	i = 0;
	while (++i <= prm.ants)
		ft_printf("L%i-%s ", i, end->name);
	ft_printf("\n");
	return (1);
}

static void		ft_printing_ants(t_nodes *nodes, t_lemin prm)
{
	if (nodes->came_from->ant_n > prm.ants)
		(nodes->ant_n)++;
	if (nodes->came_from->ant_n <= prm.ants
		&& nodes->came_from->ant_n > 0)
	{
		if (nodes->came_from->came_from
			&& nodes->came_from->came_from->ant_n <= prm.ants
			&& nodes->came_from->came_from->ant_n > 0)
			ft_print_colors(prm, nodes->came_from->ant_n, nodes->name, 1);
		else
			ft_print_colors(prm, nodes->came_from->ant_n, nodes->name, 2);
		(nodes->ant_n)++;
		if (nodes->came_from->start == 1)
			(nodes->came_from->ant_n)++;
	}
}

void			ft_print_result(t_nodes *nodes, t_lemin prm)
{
	t_nodes	*end;

	if (prm.c)
	{
		srand(time(NULL));
		prm.color = rand() % 255;
		prm.crn = rand() % 255;
	}
	ft_printf("%s\n\n", prm.input);
	if (prm.proad)
		ft_print_road(nodes);
	end = ft_find_end(nodes);
	if (end->came_from->start == 1 && ft_start_fin(prm, end))
		return ;
	while (end->ant_n < prm.ants)
	{
		nodes = end;
		while (nodes->start != 1)
		{
			ft_printing_ants(nodes, prm);
			nodes = nodes->came_from;
		}
		ft_printf("\n");
	}
}
