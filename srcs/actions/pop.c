/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:29:09 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 14:29:10 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

t_stack	*pop(t_stack *stack)
{
	int		i;
	t_stack	*new;

	if (!is_empty(*stack))
		new = new_stack(stack->len - 1);
	else
		new = new_stack(0);
	i = -1;
	while (++i < new->len)
		new->tab[i] = stack->tab[i + 1];
	ft_bzero(stack->tab, stack->len);
	free(stack);
	stack = new;
	return (stack);
}
