/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:43:54 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/07 18:09:04 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	partition (t_stack *stack, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = stack->tab[high];
	i = (low - 1); 
	j = low - 1;
	while (++j <= high - 1)
	{
		if (stack->tab[j] < pivot)
		{
			i++;
			ft_swap(&stack->tab[i], &stack->tab[j]);
		}
	}
	ft_swap(&stack->tab[i + 1], &stack->tab[high]);
	return (i + 1);
}

void quick_sort(t_stack *stack, int low, int high)
{
	int		pindex;

	if (low < high)
	{
		printf("\nPerforming Quick Sort...\n");
		pindex = partition(stack, low, high);
        display_stack(stack);
		quick_sort(stack, low, pindex - 1);
		quick_sort(stack, pindex + 1, high);
	}
}
