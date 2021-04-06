/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:32:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 20:10:35 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*create_stack(size_t size)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	if (size > 0)
		stack->tab = (int *)malloc(sizeof(int) * size);
	else
		stack->tab = NULL;
	stack->size = size;
	return (stack);
}
