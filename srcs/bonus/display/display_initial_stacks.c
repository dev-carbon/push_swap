/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_initial_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:07:00 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 12:07:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_initial_stacks(t_vars *vars)
{
	if (vars->options[VERBOSE] == ON)
	{
		ft_putstr("\e[4mInitial stacks\e[0m:\n");
		display_stacks(*vars->stack_a, *vars->stack_b);
	}
}
