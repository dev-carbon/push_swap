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

t_vars	*sort(t_vars *vars)
{
	int	temp;
	t_action	*action;

	action = NULL;
    while (!is_empty(vars->stack_a))
    {
		write(1, "pb\n", 3);
		// printf("what action ??\n");
		temp = peek(vars->stack_a);
        vars->stack_a = pop(vars->stack_a);
		
		
		while (!is_empty(vars->stack_b) && peek(vars->stack_b) > temp)
        {
			write(1, "pa\n", 3);
			action = set_action(action, PUSH_A);
			execute(vars, action);
			// display_stacks(*vars->stack_a, *vars->stack_b);
        }
		write(1, "pb\n", 3);
		// action = set_action(action, PUSH_B);
        // execute(vars, action);
		
		
		vars->stack_b = push(vars->stack_b, temp);
		// display_stacks(*vars->stack_a, *vars->stack_b);
    }
	while (!is_empty(vars->stack_b))
	{
		write(1, "pa\n", 3);
		action = set_action(action, PUSH_A);
        execute(vars, action);
		// display_stacks(*vars->stack_a, *vars->stack_b);
	}
    return (vars);
}

int				push_swap(t_vars *vars)
{
	ft_putstr("Init stack:\n_\n");
	display_stacks(*vars->stack_a, *vars->stack_b);
	sort(vars);
	ft_putstr("Sort result:\n_\n");
	display_stacks(*vars->stack_a, *vars->stack_b);
	is_sorted(vars->stack_a) && is_empty(vars->stack_b) ?
		ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
