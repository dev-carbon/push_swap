/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:19:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 18:19:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

static void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

static void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

static void	rev_rotate_both(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
}

void		execute(t_stack **a, t_stack **b, t_action *action)
{
	if (ft_strncmp(action->label, "sa", action->len) == 0)
		swap(*a);
	else if (ft_strncmp(action->label, "sb", action->len) == 0)
		swap(*b);
	else if (ft_strncmp(action->label, "ss", action->len) == 0)
		swap_both(*a, *b);
	if (ft_strncmp(action->label, "pa", action->len) == 0)
	{
		*a = push(*a, *b);
		*b = pop(*b);
	}
	if (ft_strncmp(action->label, "pb", action->len) == 0)
	{
		*b = push(*b, *a);
		*a = pop(*a);
	}
	if (ft_strncmp(action->label, "ra", action->len) == 0)
		rotate(*a);
	else if (ft_strncmp(action->label, "rb", action->len) == 0)
		rotate(*b);
	else if (ft_strncmp(action->label, "rr", action->len) == 0)
		rotate_both(*a, *b);
	else if (ft_strncmp(action->label, "rra", action->len) == 0)
		rev_rotate(*a);
	else if (ft_strncmp(action->label, "rrb", action->len) == 0)
		rev_rotate(*b);
	else if (ft_strncmp(action->label, "rrr", action->len) == 0)
		rev_rotate_both(*a, *b);
}
