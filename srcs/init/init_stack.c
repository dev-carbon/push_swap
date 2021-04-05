/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:33:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 12:33:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_stack	*init_stack(t_stack *stack, t_args *args)
{
	int		i;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->tab = (int *)malloc(sizeof(int) * args->ac)))
		return (NULL);
	i = -1;
	while (++i < args->ac)
		stack->tab[i] = ft_atoi(args->av[i + 1]);
	stack->len = args->ac;
	return (stack);
}
