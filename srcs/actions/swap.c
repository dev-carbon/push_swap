/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:16:08 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 11:16:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	swap(t_stack *stack)
{
	if (!is_empty(*stack))
		ft_swap(&stack->tab[0], &stack->tab[1]);
}
