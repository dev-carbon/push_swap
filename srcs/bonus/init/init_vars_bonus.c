/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:07:12 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/12 20:50:41 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_vars	*set_option(t_vars *vars, char *label)
{
	while (*label)
	{
		if (*label == 'v' && vars->options[VERBOSE] == OFF)
			vars->options[VERBOSE] = ON;
		else if (*label == 'v' && vars->options[VERBOSE] == ON)
			exit_prog(EXIT_FAILURE, "Duplicated options\n", vars);
		if (*label == 'c' && vars->options[COLOURS] == OFF)
			vars->options[COLOURS] = ON;
		else if (*label == 'c' && vars->options[COLOURS] == ON)
			exit_prog(EXIT_FAILURE, "Duplicated options\n", vars);
		if (*label == 'i' && vars->options[ITERATE] == OFF)
			vars->options[ITERATE] = ON;
		else if (*label == 'i' && vars->options[ITERATE] == ON)
			exit_prog(EXIT_FAILURE, "Duplicated options\n", vars);
		label++;
	}
	return (vars);
}

static t_vars	*init_options(t_vars *vars)
{
	vars->options[VERBOSE] = OFF;
	vars->options[COLOURS] = OFF;
	vars->options[ITERATE] = OFF;
	return (vars);
}

t_vars			*init_vars(t_vars *vars, int argc, char **argv)
{
	int		i;
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
	init_options(vars);
	i = 0;
	while (++i < argc)
		if (*argv[i] == '-')
			vars = set_option(vars, argv[i] + 1);
		else
			split = ft_split(argv[i], ' ');
	size = ft_split_len(split);
	while (--size >= 0)
		vars->stack_a = push(vars->stack_a, ft_atoi(split[size]));
	destroy_split(split);
	vars->ops = NULL;
	return (vars);
}
