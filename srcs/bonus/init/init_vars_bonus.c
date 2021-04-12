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
	printf("label: %s\n", label);
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
	i = 0;
	while (++i < argc && *argv[i] == '-')
		vars = set_option(vars, argv[i] + 1);
	split = ft_split(argv[i], ' ');
	size = ft_split_len(split);
	while (--size >= 0)
		vars->stack_a = push(vars->stack_a, ft_atoi(split[size]));
	vars->ops = NULL;
	return (vars);
}
