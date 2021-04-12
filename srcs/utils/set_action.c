/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:30:07 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/12 21:30:40 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_action		*set_action(t_action *action, char *label)
{
	if (!(action = (t_action *)malloc(sizeof(t_action))))
		return (NULL);
	action->label = ft_strdup(label);
	action->len = ft_strlen(label);
	return (action);
}
