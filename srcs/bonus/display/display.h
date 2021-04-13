/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:56:47 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/13 11:56:50 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "include.h"


void	display_stacks(t_stack stack_a, t_stack stack_b);
void	display_initial_stacks(t_vars *vars);
void	display_final_stacks(t_vars *vars);
void	display_debug_data(t_vars *vars, int count);

#endif