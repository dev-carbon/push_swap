/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_final_stacks_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:54:50 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/28 12:42:18 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_bonus.h"

void	display_final_stacks(t_vars *vars)
{
	if (vars->options[VERBOSE] == ON)
	{
		ft_putstr("\n\n\e[4mFinal stacks\e[0m:\n");
		display_stacks(*vars->stack_a, *vars->stack_b);
	}
}
