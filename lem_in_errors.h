/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:17:14 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/17 17:28:06 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ERRORS_H
# define LEM_IN_ERRORS_H

char const	*g_errors[20] = {
	"Error: incorrect input for ants!",
	"Error: no ants!",
	"Error: number of ants can't be negative!",
	"Error: number of ants can't equal zero!",
	"Error: number of ants can't be more than MAX_INT!",
	"Error: nothing was read!",
	"Error: double start!",
	"Error: double end!",
	"Error: no connections between the nodes",
	"Error: the rooms can't have same names",
	"Error: the rooms can't have same coordinates",
	"Error: incorrect input for rooms!",
	"Error: incorrect room name!",
	"Error: no start room!",
	"Error: no end room!",
	"Error: no start and no end!",
	"Error: waiting for links, not rooms!",
	"Error: incorrect input for links!",
	"Error: there is not room with that name",
	"Error: no road from start to finish!"};

#endif
