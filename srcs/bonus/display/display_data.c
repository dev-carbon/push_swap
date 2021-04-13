/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:01:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 19:01:54 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_debug_data(t_vars *vars, int count)
{
	if (vars->options[VERBOSE] == ON)
		display_stacks(*vars->stack_a, *vars->stack_b);
	if (vars->options[COLOURS] == ON)
		printf("\e[4mLast operation\e[0m: \e[1m\e[33m%s\e[0m\n\n", vars->ops->action->label);
	if (vars->options[ITERATE] == ON)
		printf("\e[4mOperation count\e[0m: %d\n\n", count);
	ft_putstr("\e[4mExec:\e[0m ");
}
