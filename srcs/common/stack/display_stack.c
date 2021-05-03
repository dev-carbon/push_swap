/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:05:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 20:52:45 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	display_stack(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size)
		printf("%d\n", stack->tab[i]);
	write(1, "_\n\n", 3);
}
