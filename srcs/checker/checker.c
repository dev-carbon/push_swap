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

static t_ops	*store_action(t_ops *ops, char *label)
{
	t_ops *last;
	t_ops *new;

	if (!(new = (t_ops *)malloc(sizeof(t_ops))))
		return (NULL);
	if (!(new->action =  (t_action *)malloc(sizeof(t_action))))
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
	while (current)
	{
		action = current->action;
		execute(vars, action);
		current = current->next;
	}
}

int		checker(t_vars *vars)
{
	int			nbytes;
	char		buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	while ((nbytes = read(STDIN_FILENO, buf, BUF_SIZE)))
	{
		buf[nbytes - 1] = '\0';
		if (is_valid_action(buf, nbytes))
			vars->ops = store_action(vars->ops, buf);
	}
	do_ops(vars, vars->ops);
	is_sorted(vars->stack_a) && is_empty(vars->stack_b) ?
		ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
