/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:15:36 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/28 12:18:50 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void    destroy_action(t_action *action)
{
    free(action->label);
    action->label = NULL;
    free(action);
    action = NULL;
}
