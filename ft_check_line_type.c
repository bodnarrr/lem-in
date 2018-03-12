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

int 			ft_check_line_type(char *str)
{
	if (str[0] == 'L')
		 return (ERRO);
	else if (strequ(str, "##start") == 1)
		return (STRT);
	else if (strequ(str), "##end" == 1)
		return (FNSH);
	else if ((str)[0] == '#' && !strequ(str, "##end")
		&& !strequ(str, "##start"))
		return (CMNT);
	else if (ft_str_allnum(str) == 1 && ft_atoi(str) > 0
		&& ft_atoi(str) <= MAX_INT)
		return (ANTS);
	else if (ft_strnsymb(str, ' ') == 2
		&& ft_check_if_room(ft_strsplit(str), ' '))
		return (ROOM);
	else if (ft_strnsymb(str, '-') == 1)
		return (CONN);
	return (ERRO);
}
