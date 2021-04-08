/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:51:26 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/07 15:51:29 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	val;

	(void)stack_b;
	printf("Initial stack.\n--------------\n");
	display_stack(stack_a);
	printf("Performing insertion sort...\n_\n\n");
	j = 0;
	while (++j < stack_a->size)
	{
		val = stack_a->tab[j];
		i = j - 1;
		while (i >= 0 && stack_a->tab[i] > val)
		{
			stack_a->tab[i + 1] = stack_a->tab[i];
			i -= 1;
		}
		stack_a->tab[i + 1] = val;
	}
	printf("Insertion sort performed.\n");
	printf("Final Stack.\n");
	display_stack(stack_a);
}
