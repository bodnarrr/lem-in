/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:21:26 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 16:36:33 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_join_lem(char **str1, char **str2, t_lemin *prm)
{
	char	*res;
	char	*newline;

	if (prm->line == 0)
		res = ft_str_clean_join(str1, str2);
	else
	{
		newline = ft_strdup("\n");
		res = ft_str_clean_join(str1, &newline);
		res = ft_str_clean_join(&res, str2);
	}
	return (res);
}
