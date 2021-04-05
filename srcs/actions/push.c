/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:49:36 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 12:49:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

t_stack	*push(t_stack *dst, t_stack *src)
{
	int		i;
	t_stack	*tmp_dst;

	if (!is_empty(*src))
	{
		tmp_dst = new_stack(dst->len + 1);
		// printf("dst len: %d\n", tmp_dst->len);
		tmp_dst->tab[0] = src->tab[0];
		i = 0;
		while (++i < tmp_dst->len)
	 		tmp_dst->tab[i] = dst->tab[i - 1];
		dst = tmp_dst;
	}
	return (dst);
}
