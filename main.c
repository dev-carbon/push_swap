/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:45:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 12:45:42 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
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
