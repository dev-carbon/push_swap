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

# include "push_swap.h"

int			exit_prog(int status, t_vars *vars);
void		display_stacks(t_stack stack_a, t_stack stack_b);
void		destroy_vars(t_vars *vars);
void		destroy_ops(t_ops *ops);

#endif
