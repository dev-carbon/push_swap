/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:29:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/05/04 13:10:38 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*pop(t_stack *stack)
{
	int		i;
	t_stack	*prev;

	if (!is_empty(stack))
	{
		prev = stack;
		stack = create_stack(prev->size - 1);
		i = -1;
		while (++i < stack->size)
			stack->tab[i] = prev->tab[i + 1];
		destroy_stack(prev);
	}
	return (stack);
}
