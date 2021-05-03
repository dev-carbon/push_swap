/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_final_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:54:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 12:16:59 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_final_stacks(t_vars *vars)
{
	if (vars->options[VERBOSE] == ON)
	{
		ft_putstr("\n\n\e[4mFinal stacks\e[0m:\n");
		display_stacks(*vars->stack_a, *vars->stack_b);
	}
}
