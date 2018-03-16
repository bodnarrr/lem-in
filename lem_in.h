/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:20:29 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/16 17:59:38 by abodnar          ###   ########.fr       */
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

typedef struct s_nodes t_nodes;
typedef struct s_conns t_conns;
typedef struct s_queue t_queue;

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
	int 		ant_n;
	t_conns		*conn;
	t_nodes		*came_from;
	t_nodes		*next;
}				t_nodes;

typedef struct	s_queue
{
	t_nodes		*node;
	t_queue		*next;
}				t_queue;

typedef struct	s_lemin
{
	int			ants;
	int			road_len;
	int			err_no;
	int			line;
	char		*input;
}				t_lemin;

typedef struct	s_road
{
	char		*name;
	bool		free;
}				t_road;

typedef struct	s_antparse
{
	char		start;
	char		finish;
	char		*cur_lin;
}				t_antparse;

int				ft_get_ants_number(t_lemin *prm, t_antparse *parse);
int				ft_check_line_type(char *str);
int				ft_print_ant_err(t_lemin *prm);
void			ft_add_room(t_nodes **head, t_antparse *p, char **room);
t_nodes			*ft_get_nodes(t_lemin *prm, t_antparse *p);
void			ft_clear_lines(char **str, int lines);
t_nodes			*ft_clear_nodes(t_nodes **all);
t_nodes			*ft_check_nodes(t_nodes **all, t_antparse *p, t_lemin *prm);
t_nodes			*ft_get_connects(t_nodes **all, t_antparse *p, t_lemin *prm);
void			ft_traverse(t_nodes **all);
void			ft_print_result(t_nodes *nodes, t_lemin prm);



#endif
