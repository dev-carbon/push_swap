/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:32:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 01:04:44 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_action	*store_action(t_action *action, char *label)
{
	t_action *last;
	t_action *new;

	if (!(new = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	new->label = ft_strdup(label);
	new->len = ft_strlen(label);
	new->next = NULL;
	if (action == NULL)
		action = new;
	else
	{
		last = action;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (action);
}

static void		do_actions(t_stack **a, t_stack **b, t_action *actions)
{
	t_action	*queue;
	t_action	*action;

	queue = actions;
	while (queue)
	{
		action = queue;
		execute(a, b, action);
		queue = queue->next;
	}
}

int				checker(t_stack *a, t_action *action)
{
	int		nbytes;
	char	buf[BUF_SIZE];
	t_stack	*b;

	b = new_stack(0);
	ft_bzero(buf, BUF_SIZE);
	while ((nbytes = read(STDIN_FILENO, buf, BUF_SIZE)))
	{
		buf[nbytes - 1] = '\0';
		if (is_valid_action(buf, nbytes))
			action = store_action(action, buf);
	}
	do_actions(&a, &b, action);
	if (is_sorted(*a) && is_empty(*b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

int				main(int ac, char **av)
{
	t_args		*args;
	t_stack		*stack;
	t_action	*action;

	args = NULL;
	stack = NULL;
	action = NULL;
	if (is_valid_args(ac, av))
	{
		args = init_args(args, ac, av);
		stack = init_stack(stack, args);
		checker(stack, action);
	}
	return (0);
}