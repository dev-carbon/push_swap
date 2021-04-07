/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:46:58 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 20:02:08 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	destroy_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		ft_bzero(stack->tab, stack->size);
		free(stack->tab);
		stack->tab = NULL;
		free(stack);
		stack = NULL;
	}
}
