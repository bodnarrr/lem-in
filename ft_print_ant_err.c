/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:13:35 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 17:13:35 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_in_errors.h"

int				ft_print_ant_err(t_lemin *prm)
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
