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

#include "include.h"
#include "display.h"

static t_operation	*store_ops(t_operation *ops, char *label)
{
	t_operation *last;
	t_operation *new;

	if (!(new = (t_operation *)malloc(sizeof(t_operation))))
		return (NULL);
	if (!(new->action = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	new->action->label = ft_strdup(label);
	new->action->len = ft_strlen(label);
	new->next = NULL;
	if (ops == NULL)
		ops = new;
	else
	{
		last = ops;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (ops);
}

static void		do_ops(t_vars *vars, t_operation *operations)
{
	t_operation		*current;
	t_action	*action;

	current = operations;
	while (current)
	{
		action = current->action;
		execute(vars, action);
		current = current->next;
	}
}

static t_vars		*free_ops(t_vars *vars)
{
	free(vars->ops->action->label);
	vars->ops->action->label = NULL;
	free(vars->ops->action);
	vars->ops->action = NULL;
	free(vars->ops);
	vars->ops = NULL;
	return (vars);
}

static int		checker(t_vars *vars)
{
	int			count;
	char		*buf;

	display_initial_stacks(vars);
	count = 0;
	ft_putstr("\n\e[4mExec\e[0m: ");
	while (get_next_line(STDIN_FILENO, &buf) > 0 &&
		is_valid_operation(buf, vars))
	{
		vars->ops = store_ops(vars->ops, buf);
		do_ops(vars, vars->ops);
		count += 1;
		display_debug_data(vars, count);
		free_ops(vars);
		free(buf);
	}
	free(buf);
	display_final_stacks(vars);
	is_empty(vars->stack_b) && is_sorted(vars->stack_a) ?
		ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}

int				main(int ac, char **av)
{
	t_vars		*vars;

	vars = NULL;
	if (is_valid_args(ac, av))
	{
		vars = init_vars(vars, ac, av);
		checker(vars);
		destroy_vars(vars);
	}
	return (0);
}
