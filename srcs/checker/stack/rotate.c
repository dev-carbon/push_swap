/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:47:24 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 15:47:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	int	i;
	int	first;

	if (!is_empty(stack))
	{
		first = stack->tab[0];
		i = -1;
		while (++i < stack->size - 1)
			ft_swap(&stack->tab[i], &stack->tab[i + 1]);
		stack->tab[stack->size - 1] = first;
	}
}
