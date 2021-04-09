/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:02:44 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/09 06:02:50 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

int			is_sorted(t_stack *stack);
t_vars		*sort(t_vars *vars);
t_action	*set_action(t_action *action, char *label);

#endif
