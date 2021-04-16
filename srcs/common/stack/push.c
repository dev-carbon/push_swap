/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:49:36 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 12:49:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*push(t_stack *stack, int top)
{
	int		i;
	t_stack	*prev;

	prev = stack;
	stack = create_stack(prev->size + 1);
	stack->tab[0] = top;
	i = 0;
	while (++i < stack->size)
		stack->tab[i] = prev->tab[i - 1];
	destroy_stack(prev);
	return (stack);
}
