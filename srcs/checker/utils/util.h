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

int			exit_prog(int status);
int			is_empty(t_stack stack);
int			is_sorted(t_stack stack);
void		print_initial_stack(t_stack stack);
void		print_stack(t_stack stack_a, t_stack stack_b);
t_stack		*new_stack(int len);

#endif
