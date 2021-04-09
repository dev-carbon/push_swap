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

#include "push_swap.h"

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

	if (!is_empty(*src))
	{
		top = peek(*src);
		*src = pop(*src);
		*dst = push(*dst, top);
	}
}

t_vars		*execute(t_vars *vars, t_action *action)
{
	write(1, action->label, LABEL_MAX_LEN);
	if (ft_strncmp(action->label, SWAP_A, action->len) == 0)
		swap(vars->stack_a);
	else if (ft_strncmp(action->label, SWAP_B, action->len) == 0)
		swap(vars->stack_b);
	else if (ft_strncmp(action->label, SWAP_AB, action->len) == 0)
		swap_both(vars->stack_a, vars->stack_b);
	else if (ft_strncmp(action->label, PUSH_A, action->len) == 0)
		do_push(&vars->stack_a, &vars->stack_b);
	else if (ft_strncmp(action->label, PUSH_B, action->len) == 0)
		do_push(&vars->stack_b, &vars->stack_a);
	else if (ft_strncmp(action->label, ROTATE_A, action->len) == 0)
		rotate(vars->stack_a);
	else if (ft_strncmp(action->label, ROTATE_B, action->len) == 0)
		rotate(vars->stack_b);
	else if (ft_strncmp(action->label, ROTATE_AB, action->len) == 0)
		rotate_both(vars->stack_a, vars->stack_b);
	else if (ft_strncmp(action->label, REV_ROTATE_A, action->len) == 0)
		rev_rotate(vars->stack_a);
	else if (ft_strncmp(action->label, REV_ROTATE_B, action->len) == 0)
		rev_rotate(vars->stack_b);
	else if (ft_strncmp(action->label, REV_ROTATE_AB, action->len) == 0)
		rev_rotate_both(vars->stack_a, vars->stack_b);
	return (vars);
}
