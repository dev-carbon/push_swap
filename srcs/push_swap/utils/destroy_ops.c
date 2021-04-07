/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:57:37 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 23:57:39 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	destroy_ops(t_ops *ops)
{
	t_ops	*current;
	t_ops	*next;

	if (ops != NULL)
	{
		current = ops;
		while (current != NULL)
		{
			next = current->next;
			free(current->action->label);
			free(current->action);
			free(current);
			current = next;
		}
	}
}
