/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:21:13 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/18 19:21:14 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_colors(t_lemin prm, int n, char *name, int code)
{
	if (prm.c == 0)
	{
		if (code == 1)
			ft_printf("L%d-%s ", n, name);
		if (code == 2)
			ft_printf("L%d-%s", n, name);
	}
	if (prm.c != 0)
	{
		if (code == 1)
			ft_printf("\x1b[38;2;%u;%u;%umL%d-%s \e[0m", prm.color * n * 2,
				prm.color * n, prm.color * n / 22, n, name);
		if (code == 2)
			ft_printf("\x1b[38;2;%u;%u;%umL%d-%s\e[0m", prm.color * n * 2,
				prm.color * n, prm.color * n / 22, n, name);
	}
}
