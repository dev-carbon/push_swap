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

#include "checker.h"

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

static void	do_push(t_stack **dst, t_stack **src)
{
	int		top;

	top = -1;
	if (!is_empty(*src))
	{
		top = peek(*src);
		*src = pop(*src);
		*dst = push(*dst, top);
	}
}

void		execute(t_vars *vars, t_action *action)
{
	if (ft_strncmp(action->label, "sa", action->len) == 0)
		swap(vars->stack_a);
	else if (ft_strncmp(action->label, "sb", action->len) == 0)
		swap(vars->stack_b);
	else if (ft_strncmp(action->label, "ss", action->len) == 0)
		swap_both(vars->stack_a, vars->stack_b);
	else if (ft_strncmp(action->label, "pa", action->len) == 0)
		do_push(&vars->stack_a, &vars->stack_b);
	else if (ft_strncmp(action->label, "pb", action->len) == 0)
		do_push(&vars->stack_b, &vars->stack_a);
	else if (ft_strncmp(action->label, "ra", action->len) == 0)
		rotate(vars->stack_a);
	else if (ft_strncmp(action->label, "rb", action->len) == 0)
		rotate(vars->stack_b);
	else if (ft_strncmp(action->label, "rr", action->len) == 0)
		rotate_both(vars->stack_a, vars->stack_b);
	else if (ft_strncmp(action->label, "rra", action->len) == 0)
		rev_rotate(vars->stack_a);
	else if (ft_strncmp(action->label, "rrb", action->len) == 0)
		rev_rotate(vars->stack_b);
	else if (ft_strncmp(action->label, "rrr", action->len) == 0)
		rev_rotate_both(vars->stack_a, vars->stack_b);
}
