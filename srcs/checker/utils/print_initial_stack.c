/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_initial_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 15:16:17 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	print_initial_stack(t_stack stack)
{
	int	i;

	printf("\nInitial stack");
	printf("\n-------------\n");
	i = -1;
	while (++i < stack.len)
		printf("%d\n", stack.tab[i]);
	printf("_\na\n\n");
	printf("\n-------------\n");
}
