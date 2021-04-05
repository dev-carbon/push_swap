/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:32:23 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 12:32:33 by humanfou         ###   ########.fr       */
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

static void	perform_actions(t_stack *a, t_stack *b, t_action *actions)
{
	t_action	*queue;
	t_action	*action;
	
	queue = actions;
	while (queue)
	{
		action = queue;
		if (ft_strncmp(action->label, SWAP_A, action->len) == 0)
			swap(a);
		if (ft_strncmp(action->label, SWAP_B, action->len) == 0)
			swap(b);
		else if (ft_strncmp(action->label, PUSH_A, action->len) == 0)
		{
			ft_putstr("Exec pa\n");
			a = push(a, b);
			b = pop(b);
		}	
		else if (ft_strncmp(action->label, PUSH_B, action->len) == 0)
		{
			ft_putstr("Exec pb\n");
			b = push(b, a);
			a = pop(a);
		}
		queue = queue->next;
	}
	print_stack(*a, *b);
}

int	checker(t_stack *a, t_action *action)
{
	int		nbytes;
	char	buf[BUFFER_SIZE];
	t_stack	*b;

	b = new_stack(0);
	ft_bzero(buf, BUFFER_SIZE);
	while ((nbytes = read(STDIN_FILENO, buf, BUFFER_SIZE)))
	{
		buf[nbytes - 1] = '\0';
		if (is_valid_action(buf, nbytes))
		{
			action = store_action(action, buf);
			perform_actions(a, b, action);
		}
	}
	print_initial_stack(*a);
	perform_actions(a, b, action);
	return (1);
}
