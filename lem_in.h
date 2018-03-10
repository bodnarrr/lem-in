/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:20:29 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/09 20:20:30 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf/libftprintf.h"
# include <stdbool.h>

typedef struct	s_nodes
{
	char		*name;
	bool		visit;
	bool		start;
	bool		fin;
	int			dist;
	int			x;
	int			y;
	t_nodes		*conn;
	t_nodes		*came_from;
	t_nodes		*next;
}				t_nodes;

typedef struct	s_queue
{
	t_nodes		*room;
	t_queue		*next;
}				t_queue;

typedef struct	s_lemin
{
	int			lems;
	int			road_len;
}				t_lemin;

typedef struct	s_road
{
	char		*name;
	bool		free;
}				t_lemin;



#endif
