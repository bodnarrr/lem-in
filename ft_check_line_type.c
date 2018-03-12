/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:12:22 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/12 14:12:23 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_check_if_room(char **lines)
{
	int			res;
	char		**fordel;
	int			i;

	res = 0;
	if (ft_str_allnum(lines[1]) && ft_str_allnum(lines[2]))
		res = 1;
	fordel = lines;
	i = 0;
	while (lines[i])
	{
		ft_strdel(&(lines[i]));
		i++;
	}
	free(fordel);
	return (res);
}

/*
**      ANTS - <int>
**		ROOM - <name> <int> <int>
**		CONN - <name1>-<name2>
*/

int				ft_check_line_type(char *str)
{
	if (str[0] == 'L')
		return (ERRO);
	else if (ft_strequ(str, "##start") == 1)
		return (STRT);
	else if (ft_strequ(str, "##end") == 1)
		return (FNSH);
	else if ((str)[0] == '#' && !ft_strequ(str, "##end")
		&& !ft_strequ(str, "##start"))
		return (CMNT);
	else if (ft_str_allnum(str))
		return (ANTS);
	else if (ft_strnsymb(str, ' ') == 2
		&& ft_check_if_room(ft_strsplit(str, ' ')))
		return (ROOM);
	else if (ft_strnsymb(str, '-') == 1)
		return (CONN);
	return (ERRO);
}
