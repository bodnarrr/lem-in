/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:42:35 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/10 14:42:36 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_rooms		*ft_make_room(char *name, int x, int y, int	st_fn) //-1 for start || 1 for finish
{
	t_rooms	*ret;

	ret = (t_rooms*)malloc(sizeof(t_rooms));
	ft_bzero(ret, sizeof(t_rooms));
	ret->name = ft_strdup(name);
	ret->x = x;
	ret->y = y;
	if (st_fn == -1)
		ret->start = 1;
	else if (st_fn == 1)
		ret->fin = 1;
	return (ret);
}
