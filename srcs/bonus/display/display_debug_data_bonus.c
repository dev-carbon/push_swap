/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_debug_data_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:01:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/28 12:41:42 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_bonus.h"

void	display_debug_data(t_vars *vars, int count)
{
	if (vars->options[VERBOSE] == ON)
		display_stacks(*vars->stack_a, *vars->stack_b);
	if (vars->options[COLOURS] == ON)
	{
		ft_putstr("\e[4mLast operation\e[0m: \e[1m\e[33m");
		ft_putstr(vars->ops->action->label);
		ft_putstr("\e[0m\n\n");
	}
	if (vars->options[ITERATE] == ON)
	{
		ft_putstr("\e[4mOperation count\e[0m: ");
		ft_putnbr(count);
		ft_putstr("\e[0m\n\n");
	}
	ft_putstr("\e[4mExec:\e[0m ");
}
