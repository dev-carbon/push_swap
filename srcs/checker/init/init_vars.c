/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:07:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 22:07:15 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_vars	*init_vars(t_vars *vars, int argc, char **argv)
{
	int	i;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (NULL);
	if (!(vars->args = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	vars->args->ac = argc;
	vars->args->av = argv;
	vars->stack_a = create_stack(0);
	vars->stack_b = create_stack(0);
	i = vars->args->ac;
	while (--i > 0)
		vars->stack_a = push(vars->stack_a, ft_atoi(vars->args->av[i]));
	vars->ops = NULL;
	return (vars);
}
