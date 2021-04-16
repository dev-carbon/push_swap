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
	int		size;
	char	**split;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (NULL);
	if (!(vars->args = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	vars->args->ac = argc;
	vars->args->av = argv;
	vars->stack_a = create_stack(0);
	vars->stack_b = create_stack(0);
	split = ft_split(argv[1], ' ');
	size = ft_split_len(split);
	while (--size >= 0)
		vars->stack_a = push(vars->stack_a, ft_atoi(split[size]));
	vars->ops = NULL;
	destroy_split(split);
	return (vars);
}
