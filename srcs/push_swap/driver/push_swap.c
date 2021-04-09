/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:32:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 16:23:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	*set_action(t_action *action, char *label)
{
	if (!(action = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	action->label = ft_strdup(label);
	action->len = ft_strlen(label);
	return (action);
}

t_vars			*sort(t_vars *vars)
{
	t_action	*action;
	int			count;

	action = NULL;
	count = 0;
    while (!is_empty(vars->stack_a))
    {
		if (is_empty(vars->stack_b) && is_sorted(vars->stack_a))
			break;
		if (vars->stack_a->tab[0] > vars->stack_a->tab[1])
		{
			action = set_action(action, SWAP_A);
			execute(vars, action);
			count += 1;
		}
	    while (!is_empty(vars->stack_b) &&
			peek(vars->stack_a) < peek(vars->stack_b))
        {
			action = set_action(action, PUSH_A);
			execute(vars, action);
			count += 1;

			action = set_action(action, SWAP_A);
			execute(vars, action);
			count += 1;
        }
		if (!is_sorted(vars->stack_a))
		{
			action = set_action(action, PUSH_B);
			execute(vars, action);
			count += 1;
		}
		else
			break;
	}
	while (!is_empty(vars->stack_b))
	{
		action = set_action(action, PUSH_A);
		execute(vars, action);
		count += 1;
	}
    return (vars);
}

int				push_swap(t_vars *vars)
{
	sort(vars);
	// is_sorted(vars->stack_a) && is_empty(vars->stack_b) ?
	// 	ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
