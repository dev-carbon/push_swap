/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:32:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/14 03:31:09 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "sort.h"

static int		push_swap(t_vars *vars)
{
	sort(vars);
	return (0);
}

int				main(int ac, char **av)
{
	t_vars		*vars;

	vars = NULL;
	if (is_valid_args(ac, av))
	{
		vars = init_vars(vars, ac, av);
		push_swap(vars);
		destroy_vars(vars);
	}
	return (0);
}
