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

# define ANTS 1
# define STRT 2
# define FNSH 3
# define CMNT 4
# define ROOM 5
# define CONN 6
# define ERRO 0


# include "libftprintf/libftprintf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct	s_conns
{
	t_nodes		*node;
	t_conns		*next;
}				t_conns;

typedef struct	s_nodes
{
	char		*name;
	bool		visit;
	bool		start;
	bool		fin;
	int			dist;
	int			x;
	int			y;
	t_conns		*conn;
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
	char		*input;
}				t_lemin;

typedef struct	s_road
{
	char		*name;
	bool		free;
}				t_lemin;

typedef struct	s_lemparse
{
	uint8_t		stage;
	bool		start;
	bool		finish;
	bool		ants;
	int			err_no;
	char		*curr_line;


}				t_lemparse;


#endif
