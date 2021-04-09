/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:49:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 20:50:09 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
