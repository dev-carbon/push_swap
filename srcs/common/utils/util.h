/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:24:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/04 13:36:55 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "include.h"

int			exit_prog(int status, char *msg, t_vars *vars);
void		destroy_vars(t_vars *vars);
t_operation	*destroy_ops(t_operation *ops);
void		destroy_split(char **split);
void		execute(t_vars *vars, t_action *action);
t_action	*set_action(t_action *action, char *label);
void        destroy_action(t_action *action);

#endif
