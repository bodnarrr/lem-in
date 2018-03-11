/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:17:14 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/11 13:17:15 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ERRORS_H
# define LEM_IN_ERRORS_H

char	*errors[4] = 
	{
		"Error: no ants!\n",
		"Error: incorrect ants number!\n",
		"Error: incorrect input format!\n",
		"Error: there is no room with that name!\n",

	};

int	line_type;
//1 - ants
//2 - start
//3 - finish
//4 - comment
//5 - connection
//6 - error
#endif
