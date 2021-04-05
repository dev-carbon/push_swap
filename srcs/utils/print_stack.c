/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:20:16 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 11:20:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	print_stack(t_stack a, t_stack b)
{
	int	i;

	if (a.len > b.len)
	{
		i = -1;
		while (++i < b.len)
			printf("%d %d\n", a.tab[i], b.tab[i]);
		while (i < a.len)
			printf("%d\n", a.tab[i++]);
	}
	else
	{
		i = -1;
		while (++i < a.len)
			printf("%d %d\n", a.tab[i], b.tab[i]);
		while (i < b.len)
			printf("  %d\n", b.tab[i++]);
	}
	printf("_ _\n");
	printf("a b\n\n");
}