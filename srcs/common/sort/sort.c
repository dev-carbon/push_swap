/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:05:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/09 06:05:56 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_vars	*swap_push_a(t_vars *vars)
{
	t_action	*action;

	action = NULL;
	while (!is_empty(vars->stack_b)
		&& peek(vars->stack_a) < peek(vars->stack_b))
	{
		action = set_action(action, PUSH_A);
		ft_putstr(action->label);
		execute(vars, action);
		destroy_action(action);
		action = set_action(action, SWAP_A);
		ft_putstr(action->label);
		execute(vars, action);
		destroy_action(action);
	}
	return (vars);
}

t_vars	*swap_a(t_vars *vars)
{
	t_action	*action;

	action = NULL;
	if (vars->stack_a->tab[0] > vars->stack_a->tab[1])
	{
		action = set_action(action, SWAP_A);
		ft_putstr(action->label);
		execute(vars, action);
		destroy_action(action);
	}
	return (vars);
}

t_vars	*push_b(t_vars *vars)
{
	t_action	*action;

	action = NULL;
	action = set_action(action, PUSH_B);
	ft_putstr(action->label);
	execute(vars, action);
	destroy_action(action);
	return (vars);
}

t_vars	*push_a(t_vars *vars)
{
	t_action	*action;

	action = NULL;
	action = set_action(action, PUSH_A);
	ft_putstr(action->label);
	execute(vars, action);
	destroy_action(action);
	return (vars);
}

t_vars	*sort(t_vars *vars)
{
	t_action	*action;

	action = NULL;
	while (!is_empty(vars->stack_a))
	{
		if (is_empty(vars->stack_b) && is_sorted(vars->stack_a))
			break ;
		swap_a(vars);
		swap_push_a(vars);
		if (!is_sorted(vars->stack_a))
			push_b(vars);
		else
			break ;
	}
	while (!is_empty(vars->stack_b))
		push_a(vars);
	return (vars);
}
