/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:47:36 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 15:47:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	rev_rotate(t_stack *stack)
{
	int	i;

	if (!is_empty(*stack))
	{
		i = stack->len - 1;
		while (--i >= 0)
			ft_swap(&stack->tab[i], &stack->tab[i + 1]);
	}
}
