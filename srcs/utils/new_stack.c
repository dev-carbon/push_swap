/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:32:41 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 13:32:43 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_stack	*new_stack(int len)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (len > 0)
		stack->tab = (int *)malloc(sizeof(int) * len);
	else
		stack->tab = NULL;
	stack->len = len;
	return (stack);
}
