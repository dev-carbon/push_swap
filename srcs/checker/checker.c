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

#include "checker.h"

static t_ops	*store_action(t_ops *ops, char *label)
{
	t_ops *last;
	t_ops *new;

	if (!(new = (t_ops *)malloc(sizeof(t_ops))))
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

static void		do_ops(t_vars *vars, t_ops *operations)
{
	t_ops		*current;
	t_action	*action;

	current = operations;
	ft_putstr("\nExec ");
	while (current)
	{
		action = current->action;
		ft_putstr(action->label);
		ft_putstr(" ");
		execute(vars, action);
		current = current->next;
	}
}

int				checker(t_vars *vars)
{
	int			nbytes;
	char		buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	printf("Initial Stack:\n-------------\n");
	display_stack(vars->stack_a);
	printf("Waiting for commands...\n\n");
	while ((nbytes = read(STDIN_FILENO, buf, BUF_SIZE)))
	{
		buf[nbytes - 1] = '\0';
		if (is_valid_action(buf, nbytes, vars))
		{
			vars->ops = store_action(vars->ops, buf);
			do_ops(vars, vars->ops);
			ft_putstr("\b:\n-------\n");
			display_stacks(*vars->stack_a, *vars->stack_b);
			free(vars->ops->action->label);
			free(vars->ops->action);
			free(vars->ops);
			vars->ops = NULL;
		}
	}
	is_sorted(vars->stack_a) && is_empty(vars->stack_b) ?
		ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
