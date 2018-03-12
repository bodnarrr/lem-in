/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_anterr_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:51:52 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/12 12:51:53 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_anterr_type(char *str, t_lemin *prm)
{
	if (ft_check_line_type(str) != ANTS && ft_check_line_type(str) != CMNT)
		prm->err_no = 0;
	if (ft_str_allnum(str))
	{
		if (ft_atoi(str) < 0)
			prm->err_no = 1;
		else if (ft_atoi(str) == 0)
			prm->err_no = 2;
		else if (ft_atoi(str) > MAX_INT)
			prm->err = 3;
	}
	else if ()

}
