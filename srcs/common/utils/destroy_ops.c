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

t_operation	*destroy_ops(t_operation *ops)
{
	t_operation	*current;
	t_operation	*next;

	if (ops != NULL)
	{
		current = ops;
		while (current != NULL)
		{
			next = current->next;
			free(current->action->label);
			current->action->label = NULL;
			free(current->action);
			current->action = NULL;
			free(current);
			current = next;
		}
		ops = NULL;
	}
	return (ops);
}
