/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:20:16 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 20:08:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	display_stacks(t_stack a, t_stack b)
{
	int	i;

	printf("\n");
	if (a.size > b.size)
	{
		i = -1;
		while (++i < b.size)
			printf("%d %d\n", a.tab[i], b.tab[i]);
		while (i < a.size)
			printf("%d\n", a.tab[i++]);
	}
	else
	{
		i = -1;
		while (++i < a.size)
			printf("%d %d\n", a.tab[i], b.tab[i]);
		while (i < b.size)
			printf("  %d\n", b.tab[i++]);
	}
	printf("_ _\n");
	printf("a b\n\n");
}
