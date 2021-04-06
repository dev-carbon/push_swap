/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:53:53 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 23:53:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	destroy_vars(t_vars *vars)
{
	if (vars != NULL)
	{
		destroy_stack(vars->stack_a);
		destroy_stack(vars->stack_b);
		destroy_ops(vars->ops);
		free(vars->args);
		free(vars);
		vars = NULL;
	}
}
